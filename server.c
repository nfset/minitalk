/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:18:18 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/08 17:18:40 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void	decode_message(int sig)
{
	int 	bits;

	bits = 8;
	while (bits > 0)
	{

		bits--;
	}
}
void    welcome_message()
{
    printf(".-.   .-..-..-. .-..-. .---.  .--.  .-.   .-. .-. \n");
    printf("|  `.'  || ||  `| || |{_   _}/ {} \\ | |   | |/ /  \n");
    printf("| |\\ /| || || |\\  || |  | | /  /\\  \\| `--.| |\\ \\  \n");
    printf("`-' ` `-'`-'`-' `-'`-'  `-' `-'  `-'`----'`-' `-' \n");
}

	
int	main(void)
{
	int server_pid;

	server_pid = getpid();
	welcome_message();
	printf("Server process id is: %d\n", server_pid);
	signal(SIGUSR1, decode_message);
	signal(SIGUSR2, decode_message);
	while (1)
	{
		pause();
	}
	return (0);
}