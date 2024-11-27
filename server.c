/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:18:24 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 17:34:25 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

static unsigned char	*g_res = NULL;

/* ---------------------- Support function prototypes ---------------------- */

static void	sig_handler(int sig, siginfo_t *info, void *context);
static void	end_communication(pid_t client_pid);
static void	add_char_to_message(unsigned char curr_char);

/* ---------------------------- Server Programme ---------------------------- */

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1 || !argv)
		return (ft_printf("Usage: ./server\n"));
	m_sigaction_init(&sa, sig_handler);
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
			add_char_to_message(curr_char);
		curr_char = 0;
	}
	m_kill_safe(curr_client, SIGUSR1, g_res);
}

static void	end_communication(pid_t client_pid)
{
	ft_printf("%s", g_res);
	free(g_res);
	g_res = NULL;
	m_kill_safe(client_pid, SIGUSR2, g_res);
	ft_printf("\n----- end of message from %d -----\n", client_pid);
}

static void	add_char_to_message(unsigned char curr_char)
{
	unsigned char	*tmp;
	static size_t	capacity;
	static size_t	len;

	if (!g_res)
	{
		capacity = 100;
		len = 0;
		g_res = (unsigned char *)malloc((capacity + 1) * sizeof(char));
		if (!g_res)
			exit(7);
	}
	if (len >= capacity)
	{
		capacity = len * 2;
		tmp = (unsigned char *)ft_realloc((void *)g_res, capacity);
		if (!tmp)
		{
			free(g_res);
			exit(8);
		}
		g_res = tmp;
	}
	g_res[len++] = curr_char;
	g_res[len] = '\0';
}
