/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:36:39 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	hash_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	if (flag->hash && content)
	{
		if (!ft_putstr_printf("0x", count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	x_width_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	width;
	int	hash_count;
	int	digits;
	int	flag_width_plus_zero;

	if (flag->hash && content)
		hash_count = 2;
	else
		hash_count = 0;
	digits = flag_strlen(content, buffer, flag);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits + hash_count && !flag->minus
		&& (!flag->zero || flag->dot))
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - hash_count;
		else
			width = flag_width_plus_zero - digits - hash_count;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

bool	x_minus_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	width;
	int	hash_count;
	int	digits;
	int	flag_width_plus_zero;

	if (flag->hash && content)
		hash_count = 2;
	else
		hash_count = 0;
	digits = flag_strlen(content, buffer, flag);
	flag_width_plus_zero = flag->width;
	if (flag_width_plus_zero > digits + hash_count && flag->minus)
	{
		if (flag->precision > digits)
			width = flag_width_plus_zero - flag->precision - hash_count;
		else
			width = flag_width_plus_zero - digits - hash_count;
		if (!space_print_malloc(width, count, buffer))
			return (false);
	}
	return (true);
}

bool	x_before_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	int	digits;
	int	hash_count;

	if (flag->hash && content)
		hash_count = 2;
	else
		hash_count = 0;
	digits = flag_strlen(content, buffer, flag);
	if (!x_width_print(content, count, flag, buffer))
		return (false);
	if (!hash_print(content, count, flag, buffer))
		return (false);
	if (flag->width > digits && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print_malloc(flag->width - digits - hash_count, count,
				buffer))
			return (false);
	}
	if (flag->precision > digits && flag->dot)
	{
		if (!zero_print_malloc(flag->precision - digits, count, buffer))
			return (false);
	}
	return (true);
}

bool	x_specifier(unsigned int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;

	buffer = itoa_ubase((uintptr_t)content, "0123456789abcdef");
	if (!buffer)
		return (false);
	digits = flag_strlen(content, buffer, flag);
	if (!x_before_print(content, count, flag, buffer))
		return (false);
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
		{
			free(buffer);
			return (false);
		}
	}
	if (!x_minus_print(content, count, flag, buffer))
		return (false);
	free(buffer);
	return (true);
}
