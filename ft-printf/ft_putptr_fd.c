/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:41 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/14 13:15:25 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putptr_fd(unsigned long long n, int fd)
{
	size_t	len;
	char	*base;

	if (fd < 0)
		return (0);
	if (!n)
		return (write(1, "(nil)", 5));
	base = "0123456789abcdef";
	len = 0;
	if (n > 15)
		len += ft_putptr_fd(n / 16, fd);
	if (len == 0)
		len += write(fd, "0x", 2);
	len += write(fd, &base[n % 16], 1);
	return (len);
}
