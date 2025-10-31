/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 18:23:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static bool	print_specifier(const char sp, va_list ap, int *count, t_flag *flag)
{
	bool	is_print;

	is_print = 0;
	if (sp == 'c')
		is_print = c_specifier((char)va_arg(ap, int), count, flag);
	else if (sp == 's')
		is_print = s_specifier(va_arg(ap, char *), count, flag);
	else if (sp == 'p')
		is_print = p_specifier(va_arg(ap, void *), count, flag);
	else if (sp == 'd' || sp == 'i')
		is_print = di_specifier(va_arg(ap, int), count, flag);
	else if (sp == 'u')
		is_print = u_specifier(va_arg(ap, unsigned int), count, flag);
	else if (sp == 'x')
		is_print = x_specifier(va_arg(ap, unsigned int), count, flag);
	else if (sp == 'X')
		is_print = x_upper_specifier(va_arg(ap, unsigned int), count, flag);
	else if (sp == '%')
		is_print = parcent_specifier(count, flag);
	if (!is_print)
		return (false);
	return (true);
}

static bool	is_valid_printf(const char **format, va_list ap, int *count)
{
	t_flag	flag;

	flag_initialization(&flag);
	if (!flag_check(format, &flag))
		return (false);
	if (is_specifier(**format))
		return (print_specifier(**format, ap, count, &flag));
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
