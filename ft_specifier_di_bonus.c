/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_di_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 22:10:36 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	di_sign_print(int content, int *count, t_flag *flag, char *buffer)
{
	if (content < 0)
	{
		if (!ft_putchar_printf('-', count))
		{
			free(buffer);
			return (false);
		}
	}
	else if (flag->plus)
	{
		if (!ft_putchar_printf('+', count))
		{
			free(buffer);
			return (false);
		}
	}
	else if (flag->space)
	{
		if (!ft_putchar_printf(' ', count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	di_width_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;
	int	flag_width_plus_zero;

	digits = flag_strlen(content, buffer, flag);
	sign = (content < 0 || flag->plus || flag->space);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits + sign && !flag->minus && (!flag->zero
			|| flag->dot))
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - sign;
		else
			width = flag_width_plus_zero - digits - sign;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

bool	di_minus_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;
	int	flag_width_plus_zero;

	digits = flag_strlen(content, buffer, flag);
	sign = (content < 0 || flag->plus || flag->space);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits + sign && flag->minus)
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - sign;
		else
			width = flag_width_plus_zero - digits - sign;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

static bool	di_before_print(int content, int *count, t_flag *flag, char *buffer)
{
	int		digits;
	int		sign;

	sign = (content < 0 || flag->plus || flag->space);
	digits = flag_strlen(content, buffer, flag);
	if (!di_width_print(content, count, flag, buffer))
		return (false);
	if (!di_sign_print(content, count, flag, buffer))
		return (false);
	if (flag->width > digits && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print_malloc(flag->width - digits - sign, count, buffer))
			return (false);
	}
	if (flag->precision > digits && flag->dot)
	{
		if (!zero_print_malloc(flag->precision - digits, count, buffer))
			return (false);
	}
	return (true);
}

bool	di_specifier(int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;
	long	tmp;

	tmp = (long)content;
	if (content < 0)
		tmp *= -1;
	buffer = itoa_base((uintptr_t)tmp, "0123456789");
	if (!buffer)
		return (false);
	digits = flag_strlen(content, buffer, flag);
	if (!di_before_print(content, count, flag, buffer))
		return (false);
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
		{
			free(buffer);
			return (false);
		}
	}
	if (!di_minus_print(content, count, flag, buffer))
		return (false);
	free(buffer);
	return (true);
}
