/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 18:48:16 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	u_width_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	width;
	int	digits;
	int	flag_width_plus_zero;

	digits = flag_strlen(content, buffer, flag);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits && !flag->minus && (!flag->zero
			|| flag->dot))
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision;
		else
			width = flag_width_plus_zero - digits;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

bool	u_minus_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	width;
	int	digits;
	int	flag_width_plus_zero;

	digits = flag_strlen(content, buffer, flag);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits && flag->minus)
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision;
		else
			width = flag_width_plus_zero - digits;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

bool	u_before_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	digits;

	digits = flag_strlen(content, buffer, flag);
	if (!u_width_print(content, count, flag, buffer))
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
	return (true);
}

bool	u_specifier(unsigned int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;

	buffer = itoa_base((uintptr_t)content, "0123456789");
	if (!buffer)
		return (false);
	digits = flag_strlen(content, buffer, flag);
	if (!u_before_print(content, count, flag, buffer))
		return (false);
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
		{
			free(buffer);
			return (false);
		}
	}
	if (!u_minus_print(content, count, flag, buffer))
		return (false);
	free(buffer);
	return (true);
}
