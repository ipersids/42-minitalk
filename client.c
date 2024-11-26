/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:18:09 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/26 15:08:17 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_printf.h"

static volatile int	g_is_received = 0;

/* ---------------------- Support function prototypes ---------------------- */

static int	is_input_valid(int argc, const char *pid);
static void	sent_message(int pid, const char *str);
static void	sig_handler(int sig, siginfo_t *info, void *context);

/* --------------------------- Client Programme ---------------------------- */

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	pid = is_input_valid(argc, argv[1]);
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
	ft_printf("Sending a message from %d to server %d...\n", getpid(), pid);
	sent_message(pid, argv[2]);
	return (0);
}

/* -------------------- Support function implementation -------------------- */

static int	is_input_valid(int argc, const char *pid)
{
	int		res;
	size_t	i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client PID \"message\".\n");
		exit(3);
	}
	i = 0;
	while (pid[i] != '\0')
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
		{
			ft_printf("ERROR: PID should be an integer.\n");
			exit(4);
		}
		i++;
	}
	res = ft_atoi(pid);
	if (res <= 0 || kill(res, 0) != 0)
	{
		ft_printf("ERROR: Invalid PID. Please try again.\n");
		exit(5);
	}
	return (res);
}

static void	sent_message(int pid, const char *str)
{
	unsigned char	ch;
	int				i;

	while (1)
	{
		ch = (unsigned char)*str++;
		i = 0;
		while (i < 8)
		{
			if ((ch >> (7 - i)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			while (g_is_received == 0)
				usleep(100);
			g_is_received = 0;
		}
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(1000);
	}
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static size_t	bits;
	static pid_t	server;

	(void)context;
	if (info->si_pid != 0)
		server = info->si_pid;
	if (sig == SIGUSR1)
	{
		bits++;
		g_is_received = 1;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Server %d has received %d bytes.\n", server, bits / 8);
		exit(EXIT_SUCCESS);
	}
}
