/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:19:26 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/13 21:45:06 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	my_putchar(int c)
{
	write(1, &c, 1);
}

void	decode_message(int sig, siginfo_t *info, void *nothing)
{
	static int	bit;
	static int	character;
	pid_t		client_id;

	client_id = info->si_pid;
	(void)nothing;
	if (sig == SIGUSR1)
		character = character | (1 << bit);
	bit++;
	if (bit == 8)
	{	
		if (character == 0)
			kill(client_id, SIGUSR2);
		my_putchar(character);
		bit = 0;
		character = 0;
	}
}

void	welcome_message(void)
{
    printf(".-.   .-..-..-. .-..-. .---.  .--.  .-.   .-. .-. \n");

    printf("|  `.'  || ||  `| || |{_   _}/ {} \\ | |   | |/ /  \n");

    printf("| |\\ /| || || |\\  || |  | | /  /\\  \\| `--.| |\\ \\  \n");

	printf("`-' ` `-'`-'`-' `-'`-'  `-' `-'  `-'`----'`-' `-' \n");
}

int	main(void)
{
    struct sigaction sig_act;
	sig_act.sa_sigaction = &decode_message;
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_flags = sigemptyset(&sig_act.sa_mask);
	int	server_pid;

	server_pid = getpid();
	welcome_message();
	printf("Server process id is: %d\n", server_pid);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}