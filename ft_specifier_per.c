/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_per_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:31:34 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	per_specifier(int *count, t_flag *flag)
{
	if (flag->width > 1 && !flag->minus && !flag->zero)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	if (flag->width > 1 && !flag->minus && flag->zero)
	{
		if (!zero_print(flag->width - 1, count))
			return (false);
	}
	if (!ft_putchar_printf('%', count))
		return (false);
	if (flag->width > 1 && flag->minus)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	return (true);
}

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
	else if (sp == 'x' || sp == 'X')
		is_print = x_specifier(va_arg(ap, unsigned int), sp, count, flag);
	else if (sp == '%')
		is_print = parcent_specifier(count, flag);
	if (!is_print)
		return (false);
	return (true);
}
