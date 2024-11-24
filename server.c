/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:18:24 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/24 20:50:43 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_printf.h"

/* ---------------------- Support function prototypes ---------------------- */

static void	sig_handler(int sig, siginfo_t *info, void *context);

/* ---------------------------- Server Programme ---------------------------- */

int	main(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
/* -------------------- Support function implementation -------------------- */

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int				cnt_bit = 0;
	static unsigned char	curr_char = 0;

	(void)context;
	// TODO: change to support UTF-8
	if (sig == SIGUSR1)
		curr_char |= (1 << (7 - cnt_bit));
	else if (sig == SIGUSR2)
		curr_char &= ~(1 << (7 - cnt_bit));
	cnt_bit++;
	if (cnt_bit == 8)
	{
		if (curr_char == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n----- end of message from %d -----\n", info->si_pid);
		}
		else
			ft_printf("%c", curr_char);
		curr_char = 0;
		cnt_bit = 0;
	}
}
