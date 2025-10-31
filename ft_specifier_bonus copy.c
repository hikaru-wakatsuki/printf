/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus copy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 21:23:28 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	di_width_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;
	int	flag_width_plus_zero;

	digits = ft_strlen(buffer);
	sign = is_sign(content, flag);
	flag_width_plus_zero = flag->width;
	if (!content && flag->dot && !flag->precision)
		flag_width_plus_zero++;
	if (flag_width_plus_zero > digits + sign && !flag->minus && (!flag->zero
			|| flag->dot))
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - sign;
		else
			width = flag_width_plus_zero - digits - sign;
		if (!space_print(width, count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	di_minus_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;
	int	flag_width_plus_zero;

	digits = ft_strlen(buffer);
	sign = is_sign(content, flag);
	flag_width_plus_zero = flag->width;
	if (!content && flag->dot && !flag->precision)
		flag_width_plus_zero++;
	if (flag_width_plus_zero > digits + sign && flag->minus)
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - sign;
		else
			width = flag_width_plus_zero - digits - sign;
		if (!space_print(width, count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	u_specifier(unsigned int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;

	buffer = itoa_base((uintptr_t)content, "0123456789");
	if (!buffer)
		return (false);
	digits = ft_strlen(buffer);
	if (!di_width_print(content, count, flag, buffer))
		return (false);
	if (flag->width > digits && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print_malloc(flag->width - digits, count, buffer))
			return (false);
	}
	if (flag->precision > digits && flag->dot)
	{
		if (!zero_print_malloc(flag->precision - digits, count, buffer))
			return (false);
	}
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
			return (false);
	}
	if (!di_minus_print(content, count, flag, buffer))
		return (false);
	free(buffer);
	return (true);
}

bool	x_specifier(unsigned int content, const char sp, int *count,
		t_flag *flag)
{
	char	*buffer;
	int		n;

	if (sp == 'x')
		buffer = itoa_ubase(content, "0123456789abcdef");
	else
		buffer = itoa_ubase(content, "0123456789ABCDEF");
	if (!buffer)
		return (false);
	n = ft_strlen(buffer);
	if (flag->dot)
		n = flag->precision;
	if (flag->width > n + 2 && flag->minus)
	{
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	if (flag->hash && sp == 'x')
	{
		if (!ft_putstr_printf("0x", count))
			return (false);
	}
	else
	{
		if (!ft_putstr_printf("0X", count))
			return (false);
	}
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	parcent_specifier(int *count, t_flag *flag)
{
	if (flag->width > 1 && !flag->minus)
	{
		if (!space_print(flag->width - 1, count))
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
