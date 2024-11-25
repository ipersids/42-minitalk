/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:19 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/01 17:54:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Locate first occurrence of character in string.
 * 
 * The terminating null-character is considered part of the C string.
 *  * When searching for 0 (null char) return a pointer to the end of the str.
 * 
 * @param str C string.
 * @param ch Character to be located. It is passed as its int promotion, 
 * but it is internally converted back to char for the comparison.
 * @return char* A pointer to the first occurrence of character in str.
 * If the character is not found, the function returns a null pointer.
 * 
 * @note If the input `str` is a NULL pointer, the function will cause 
 * 		 a segfault like the original one.
 */
char	*ft_strchr(const char *str, int ch)
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			res = (char *)(str + i);
			return (res);
		}
		i++;
	}
	if (ch == 0)
	{
		res = (char *)(str + i);
		return (res);
	}
	return (0);
}
