/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:17:09 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/15 19:16:10 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	flag;

	flag = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -flag;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * flag);
}

void	mess_recieved(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\n O CHUJ CHODZI \n");
}

void	bit_sender(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (1 << bits))
		{
			kill(pid, SIGUSR1);
			usleep(500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(500);
		}
		bits++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	signal(SIGUSR2, mess_recieved);
	if (argc != 3)
	{
		ft_printf("Try ./client SERVER_PID \"MESSAGE\"\n");
		return (1);
	}
	else if (!argv[2][0])
	{
		ft_printf("You have sent an empty message\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_sender(server_pid, argv[2][i]);
		i++;
	}
	ft_printf("You have typed: [%s] to the server\n", argv[2]);
	return (0);
}
