/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:18:18 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/15 19:34:29 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	decode_message(int sig)

{
	static int	bit;
	static int	character;

	if (sig == SIGUSR1)
		character = character | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

void	welcome_message(void)
{
	ft_printf(".-.   .-..-..-. .-..-. .---.  .--.  .-.   .-. .-. \n");
	ft_printf("|  `.'  || ||  `| || |{_   _}/ {} \\ | |   | |/ /  \n");
	ft_printf("| |\\ /| || || |\\  || |  | | /  /\\  \\| `--.| |\\ \\  \n");
	ft_printf("`-' ` `-'`-'`-' `-'`-'  `-' `-'  `-'`----'`-' `-' \n");
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	welcome_message();
	ft_printf("Server process id is: %d\n", server_pid);
	signal(SIGUSR1, decode_message);
	signal(SIGUSR2, decode_message);
	while (1)
	{
		pause();
	}
	return (0);
}
