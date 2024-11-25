/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:51:21 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/18 11:53:26 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Returns the length of the C string str.
 * 
 * The length of a C string is determined by the terminating null-character: 
 * A C string is as long as the number of characters between the beginning 
 * of the string and the terminating null character (without including '\0'
 * the terminating null character itself).
 * 
 * @param s C string.
 * @return The length of string as an unsigned int.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
