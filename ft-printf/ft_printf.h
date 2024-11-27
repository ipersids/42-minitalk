/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:02:08 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/27 19:53:31 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>	// va_list, va_start, and va_end.
# include <unistd.h>	// write()
# include <stdlib.h>	// size_t

# define SPECIFIERS "cspdiuxX%"

int		ft_printf(const char *format, ...);

size_t	ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_puthex_fd(unsigned int n, int fd, short int is_uppercase);
size_t	ft_putptr_fd(unsigned long long n, int fd);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
ssize_t	write_safe(int fd, const void *buf, size_t count);

#endif
