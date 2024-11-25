/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:12:08 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/01 17:26:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert string to integer
 * 
 * Parses the C-string str interpreting its content as an integral number, 
 * which is returned as a value of type int.
 * 
 * @param str C-string beginning with the representation of an integral number.
 * @return On success, the function returns the converted integral number as an
 * int value. If the converted value would be out of the range of representable
 * values by an int, it causes undefined behavior.
 * 
 * @note If the input `str` is a NULL pointer, the function will cause 
 * 		 a segfault like the original one.
 */
int	ft_atoi(const char *str)
{
	short int	is_negative;
	long int	res;

	is_negative = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > res * 10 && is_negative == -1)
			return (0);
		if (res > res * 10)
			return (-1);
		res *= 10;
		res += (*str - '0');
		str++;
	}
	res = (int)(res * is_negative);
	return (res);
}
