/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:42:20 by hwakatsu         ###   ########.fr       */
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
