/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:26:38 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/11 17:15:08 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	bit_sender(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (1 << bits))
		{
			kill(pid, SIGUSR1);
			usleep(420);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(420);
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
		printf("ERROR! Wrong amount of parameters. Closing Proccess!\n");
		printf("Try ./client SERVER_PID \"MESSAGE\"\n");
		return (1);
	}
	else if (!argv[2][0])
	{
		printf("You have sent an empty message\n");
		printf("It won't be shown on the server side!\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_sender(server_pid, argv[2][i]);
		i++;
	}
	printf("You have typed: [%s] to the server", argv[2]);
	return (0);
}
