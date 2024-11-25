/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:21:53 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:55 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Outputs an integer to the specified file descriptor.
 * 
 * This function writes the integer `n` to the given file descriptor `fd`.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor to which the integer is written.
 * 
 * @return size_t Number of characters that are written.
 */
size_t	ft_putnbr_fd(int n, int fd)
{
	char	ch;
	size_t	len;

	len = 0;
	if (fd < 0)
		return (0);
	ch = '0';
	if (n < 0)
	{
		len += write(fd, "-", 1);
		if (n == -2147483648)
		{
			len += write(fd, "2", 1);
			n = 147483648;
		}
		else
			n = n * (-1);
	}
	if (n > 9)
		len += ft_putnbr_fd(n / 10, fd);
	ch = ch + (n % 10);
	len += write(fd, &ch, 1);
	return (len);
}
