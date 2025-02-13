/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:17:09 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/13 21:43:42 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void    mess_recieved(int sig)
{
    printf("Your message has been recieved correctly\n");
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
	
	if (argc != 3)
	{
		printf("Try ./client SERVER_PID \"MESSAGE\"\n");
		return (1);
	}
	else if (!argv[2][0])
	{
		printf("You have sent an empty message\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_sender(server_pid, argv[2][i]);
		i++;
	}
	signal(SIGUSR2, mess_recieved);
	kill(server_pid, '\0');
	printf("You have typed: [%s] to the server", argv[2]);

	return (0);
}