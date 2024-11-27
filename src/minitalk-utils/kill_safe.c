/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:07:58 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 17:23:00 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	m_kill_safe(pid_t pid, int sig, void *allocated)
{
	if (-1 == kill(pid, sig))
	{
		ft_printf("ERROR: kill() function failed.\n");
		if (allocated != NULL)
		{
			free(allocated);
			allocated = NULL;
		}
		exit(3);
	}
}
