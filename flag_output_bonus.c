/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_output_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:30:07 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/30 07:00:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

bool	c_flag_output(int flag_count, int *count)
{
	while (flag_count - 1 > 0)
	{
		if (!ft_putchar_printf(' ', count))
			return (false);
		flag_count--;
	}
	return (true);
}

bool	s_flag_output(int flag_count, int *count)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf(' ', count))
			return (false);
		flag_count--;
	}
	return (true);
}

bool	p_space_output(int flag_count, int *count)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf(' ', count))
			return (false);
		flag_count--;
	}
	return (true);
}

bool	p_zero_print(int flag_count, int *count)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf('0', count))
			return (false);
		flag_count--;
	}
	return (true);
}
