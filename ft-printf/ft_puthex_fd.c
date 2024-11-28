/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:55:24 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/28 12:04:48 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex_fd(unsigned int n, int fd, short int is_uppercase)
{
	char	*base;
	size_t	len;

	if (is_uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n > 15)
		len += ft_puthex_fd(n / 16, fd, is_uppercase);
	len += write_safe(fd, &base[n % 16], 1);
	return (len);
}
