/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/11/01 00:01:17 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_is_digit(char const flag)
{
	return ('0' <= flag && flag <= '9');
}

int	flag_nbr_insert(const char **format)
{
	int	nbr;

	nbr = 0;
	while (ft_is_digit(**format))
	{
		nbr *= 10;
		nbr += **format - '0';
		(*format)++;
	}
	return (nbr);
}

static void	dot_insert(const char **format, t_flag *flag)
{
	(*format)++;
	flag->dot = true;
	if (ft_is_digit(**format))
		flag->precision = flag_nbr_insert(format);
	else
		flag->precision = 0;
}

static void	flag_insert(const char **format, t_flag *flag)
{
	char	c;

	c = *(*format)++;
	if (c == '-')
	{
		flag->minus = true;
		flag->zero = false;
	}
	else if (c == '0' && !flag->minus)
		flag->zero = true;
	else if (c == '#')
		flag->hash = true;
	else if (c == '+')
	{
		flag->plus = true;
		flag->space = false;
	}
	else if (c == ' ' && !flag->plus)
		flag->space = true;
}

bool	flag_check(const char **format, t_flag *flag)
{
	while (**format)
	{
		if (is_specifier(**format))
			return (true);
		if (is_flag_char(**format))
			flag_insert(format, flag);
		else if (**format == '.')
			dot_insert(format, flag);
		else if (ft_is_digit(**format))
			flag->width = flag_nbr_insert(format);
		else
			return (false);
	}
	return (false);
}
