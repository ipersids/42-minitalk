/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:59 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 13:13:27 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	m_sigaction_init(
	struct sigaction *sa, void (*handler) (int, siginfo_t *, void *))
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = handler;
	if (-1 == sigemptyset(&sa->sa_mask)
		|| -1 == sigaddset(&sa->sa_mask, SIGUSR1)
		|| -1 == sigaddset(&sa->sa_mask, SIGUSR2))
	{
		ft_printf("ERROR: Signal initialisation failed.\n");
		exit(1);
	}
	if (-1 == sigaction(SIGUSR1, sa, NULL)
		|| -1 == sigaction(SIGUSR2, sa, NULL))
	{
		ft_printf("ERROR: sigaction() system call failed.\n");
		exit(2);
	}
}
