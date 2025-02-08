/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:26:38 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/08 17:18:05 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int	main(int argc, char **argv)
{
	if (argc != 3 || !argv[2][0])
	{
		printf("ERROR! You typed not enough parameters, or one of them is wrong! CLOSING PROCESS");
		return (1);
	}
		int	server_pid;
		
		server_pid = atoi(argv[1]);
		kill(server_pid, SIGUSR1);
		printf("You have typed: [%s] to the server", argv[2]);
	
	
	return (0);
}
