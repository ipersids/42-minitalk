/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:40:49 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 17:38:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	unsigned char	*res;
	unsigned char	*tmp;
	size_t			i;

	res = (unsigned char *) malloc(new_size + 1);
	if (!res)
		return (NULL);
	tmp = (unsigned char *)ptr;
	i = 0;
	while ('\0' != tmp[i] && i < new_size)
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	free(ptr);
	return ((void *)res);
}
