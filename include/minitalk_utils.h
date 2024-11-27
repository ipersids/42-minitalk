/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:19:58 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 17:25:24 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <signal.h>
# include <stdlib.h>

# include "ft_printf.h"

void	m_sigaction_init(
			struct sigaction *sa, void (*handler) (int, siginfo_t *, void *));
void	m_kill_safe(pid_t pid, int sig, void *);

void	*ft_realloc(void *ptr, size_t new_size);

#endif