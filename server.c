/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:18:24 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/26 15:31:17 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_printf.h"

/* ---------------------- Support function prototypes ---------------------- */

static void	sig_handler(int sig, siginfo_t *info, void *context);
static void	end_communication(pid_t client_pid);

/* ---------------------------- Server Programme ---------------------------- */

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1 || !argv)
		return (ft_printf("Usage: ./server\n"));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigemptyset(&sa.sa_mask) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
	{
		ft_printf("ERROR: Signal initialisation failed.\n");
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("ERROR: sigaction() system call failed.\n");
		return (2);
	}
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

/* -------------------- Support function implementation -------------------- */

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				cnt_bit;
	static unsigned char	curr_char;
	static pid_t			curr_client;

	(void)context;
	if (info->si_pid != 0)
		curr_client = info->si_pid;
	if (sig == SIGUSR1)
		curr_char |= (1 << (7 - cnt_bit));
	else if (sig == SIGUSR2)
		curr_char &= ~(1 << (7 - cnt_bit));
	cnt_bit++;
	if (cnt_bit == 8)
	{
		cnt_bit = 0;
		if (curr_char == '\0')
		{
			curr_char = 0;
			return (end_communication(curr_client));
		}
		else
			ft_printf("%c", curr_char);
		curr_char = 0;
	}
	kill(curr_client, SIGUSR1);
}

static void	end_communication(pid_t client_pid)
{
	kill(client_pid, SIGUSR2);
	ft_printf("\n----- end of message from %d -----\n", client_pid);
}
