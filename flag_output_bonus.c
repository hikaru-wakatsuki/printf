/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_output_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:30:07 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 21:51:45 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

bool	before_flag_output(t_flag *flag, int *count)
{
	if (flag->width)
	{
		while (flag->width)
		{
			if (!ft_putchar_printf(' ', count))
				return (false);
			(flag->width)--;
		}
	}
}

bool	after_flag_output(t_flag *flag, int *count)
{
	if (flag->width)
	{
		while (flag->width)
		{
			if (!ft_putchar_printf(' ', count))
				return (false);
			(flag->width)--;
		}
	}
}
