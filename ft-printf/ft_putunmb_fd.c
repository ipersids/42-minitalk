/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunmb_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:03:33 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/13 18:32:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Outputs an unsigned integer to the specified file descriptor.
 * 
 * This function writes the unsigned integer `n` 
 * to the given file descriptor `fd`.
 * 
 * @param n The unsigned integer to output.
 * @param fd The file descriptor to which the integer is written.
 * 
 * @return size_t Number of characters that are written.
 */
size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	char	ch;
	size_t	len;

	len = 0;
	if (fd < 0)
		return (0);
	ch = '0';
	if (n > 9)
		len += ft_putunbr_fd(n / 10, fd);
	ch = ch + (n % 10);
	len += write(fd, &ch, 1);
	return (len);
}
