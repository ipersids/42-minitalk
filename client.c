/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:18:09 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/24 20:53:54 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_printf.h"

static volatile int	g_is_received = 0;

/* ---------------------- Support function prototypes ---------------------- */

static int	is_pid_valid(const char *pid);
static void	sent_message(int pid, const char *str);
static void	handle_answer(int sig);

/* --------------------------- Client Programme ---------------------------- */

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("ERROR: Less than 3 arguments.\n");
		exit(EXIT_FAILURE);
	}
	pid = is_pid_valid(argv[1]);
	signal(SIGUSR1, handle_answer);
	signal(SIGUSR2, handle_answer);
	ft_printf("Sending a message from %d to server %d...\n", getpid(), pid);
	sent_message(pid, argv[2]);
	while (!g_is_received)
		pause();
	ft_printf("SUCCESS.\nBue!\n");
	return (0);
}

/* -------------------- Support function implementation -------------------- */

static int	is_pid_valid(const char *pid)
{
	int		res;
	size_t	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
		{
			ft_printf("ERROR: PID should be an integer.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	res = ft_atoi(pid);
	if (res <= 0 || kill(res, 0) != 0)
	{
		ft_printf("ERROR: Invalid PID. Please try again.\n");
		exit(EXIT_FAILURE);
	}
	return (res);
}

static void	sent_message(int pid, const char *str)
{
	unsigned char	ch;
	int				i;

	while (*str)
	{
		ch = (unsigned char)*str++;
		i = 0;
		while (i < 8)
		{
			if ((ch >> (7 - i)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	handle_answer(int sig)
{
	if (sig == SIGUSR1)
		g_is_received = 1;
}
