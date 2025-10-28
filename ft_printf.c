/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 17:41:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_specifier(char const flag)
{
	if (flag == 'c' || flag == 's' || flag == 'p' || flag == 'd' || flag == 'i')
		return (true);
	else if (flag == 'u' || flag == 'x' || flag == 'X' || flag == '%')
		return (true);
	return (false);
}

static bool	print_specifier(const char flag, va_list ap, int *count)
{
	bool	is_print;

	is_print = 0;
	if (flag == 'c')
		is_print = ft_putchar_printf((char)va_arg(ap, int), count);
	else if (flag == 's')
		is_print = s_specifier(va_arg(ap, char *), count);
	else if (flag == 'p')
		is_print = p_specifier(va_arg(ap, void *), count);
	else if (flag == 'd' || flag == 'i')
		is_print = ft_putnbr_printf(va_arg(ap, int), count);
	else if (flag == 'u')
		is_print = ft_unsigned_putnbr_printf(va_arg(ap, unsigned int), count);
	else if (flag == 'x' || flag == 'X')
		is_print = x_specifier(va_arg(ap, unsigned int), flag, count);
	else if (flag == '%')
		is_print = ft_putchar_printf('%', count);
	if (!is_print)
		return (false);
	return (true);
}

static bool	is_valid_printf(const char **format, va_list ap, int *count)
{
	while (**format)
	{
		if (is_specifier(**format))
		{
			if (print_specifier(**format, ap, count))
				return (true);
			else
				return (false);
		}
		(*format)++;
	}
	return (false);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!is_valid_printf(&format, ap, &count))
				return (count);
		}
		else
		{
			if (!ft_putchar_printf(*format, &count))
				return (count);
		}
		++format;
	}
	va_end(ap);
	return (count);
}
