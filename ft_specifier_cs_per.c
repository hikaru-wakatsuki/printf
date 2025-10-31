/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_cs_per.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:40:23 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	c_specifier(int content, int *count, t_flag *flag)
{
	if (flag->width > 1 && !flag->minus)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	if (!ft_putchar_printf((char)content, count))
		return (false);
	if (flag->width > 1 && flag->minus)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	return (true);
}

static bool	s_null(int *count, t_flag *flag)
{
	if (flag->width > 6 && !flag->minus)
	{
		if (!space_print(flag->width - 6, count))
			return (false);
	}
	if (!ft_putstr_printf("(null)", count))
		return (false);
	if (flag->width > 6 && flag->minus)
	{
		if (!space_print(flag->width - 6, count))
			return (false);
	}
	return (true);
}

bool	s_specifier(char *content, int *count, t_flag *flag)
{
	int	n;

	if (!content)
		return (s_null(count, flag));
	else
		n = ft_strlen(content);
	if (flag->dot && flag->precision < n)
		n = flag->precision;
	if (flag->width > n && !flag->minus)
	{
		if (!space_print(flag->width - n, count))
			return (false);
	}
	if (!ft_putnstr_printf(content, count, n))
		return (false);
	if (flag->width > n && flag->minus)
	{
		if (!space_print(flag->width - n, count))
			return (false);
	}
	return (true);
}

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
