/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:33:28 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/15 18:16:38 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short int	format_is_valid(const char *format);
static const char	*print_content(va_list *args, const char *f, size_t *len);

/**
 * @brief Print formatted data to stdout.
 * 
 * Writes the C string pointed by format to the standard output. If format 
 * includes format specifiers (subsequences beginning with %), the additional
 * arguments following format are formatted and inserted in the resulting
 * string replacing their respective specifiers.
 * 
 * Format specifiers:
 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %p The void * pointer argument has to be printed in hexadecimal format.
 * %d Prints a decimal (base 10) number.
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %% Prints a percent sign
 * 
 * @param format C string that contains the text to be written.
 * 				 It can optionally contain embedded format specifiers
 * 				 that are replaced by the values specified in subsequent
 * 				 additional arguments and formatted as requested.
 * @param ... subsequent additional arguments.
 * @return int On success, the total number of characters written is returned.
 * 			   If an error occur, a negative number is returned.
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && format_is_valid(format + 1) != 0)
		{
			format = print_content(&args, format + 1, &len);
			continue ;
		}
		len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

		// %[flags][width][.precision][length]specifier
		// 1. Search for %
		// 4. Check specifier
		// 5. Print content or return -1 if error

static short int	format_is_valid(const char *format)
{
	if (ft_strchr(SPECIFIERS, *format) != 0)
		return (1);
	return (0);
}

static const char	*print_content(va_list *args, const char *f, size_t *len)
{
	if (*f == 'c')
		*len += ft_putchar_fd(va_arg(*args, int), 1);
	else if (*f == 's')
		*len += ft_putstr_fd(va_arg(*args, char *), 1);
	if (*f == 'd' || *f == 'i')
		*len += ft_putnbr_fd(va_arg(*args, int), 1);
	if (*f == 'u')
		*len += ft_putunbr_fd(va_arg(*args, unsigned int), 1);
	if (*f == 'x' || *f == 'X')
		*len += ft_puthex_fd(va_arg(*args, long long int), 1, *f == 'X');
	if (*f == 'p')
		*len += ft_putptr_fd((unsigned long long)va_arg(*args, void *), 1);
	else if (*f == '%' || *f == '\0')
		*len += ft_putchar_fd('%', 1);
	if (*f == '\0')
		return (f);
	return (f + 1);
}
