/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_safe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:16:58 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 19:49:50 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	write_safe(int fd, const void *buf, size_t count)
{
	ssize_t	len;

	len = write(fd, buf, count);
	if (-1 == len)
		exit(100);
	return (len);
}
