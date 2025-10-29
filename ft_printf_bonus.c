/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/29 15:08:47 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static bool	is_flag(char const flag)
{
	if (flag == '-' || flag == '0' || flag == '#' || flag == '+' || flag == ' '
		|| flag == '.')
		return (true);
	else if ('0' <= flag && flag <= '9')
		return (true);
	return (false);
}

void	flag_initialization(t_flag *flag)
{
	flag->minus = false;
	flag->zero = false;
	flag->hash = false;
	flag->plus = false;
	flag->space = false;
	flag->width = 0;
	flag->dot = false;
	flag->precision = 0;
}

bool	is_valid_printf(const char **format, va_list ap, int *count)
{
	t_flag	flag;
	int		*tmp;

	flag_initialization(&flag);
	if (!flag_check(format, &flag))
		return (false);
	if (is_specifier(**format))
	{
		if (print_specifier(**format, ap, count, flag))
			return (true);
		else
			return (false);
	}
	return (false);
}

int	flag_nbr_insert(const char **format)
{
	int	nbr;

	nbr = 0;
	while ('0' <= **format && **format <= '9')
	{
		nbr *= 10;
		nbr += **format - '0';
		(*format)++;
	}
	return (nbr);
}

void	flag_insert(const char **format, t_flag *flag)
{
	int		*tmp;
	char	tmp_flag;

	tmp_flag = *(*format)++;
	tmp = flag->width;
	if (tmp_flag == '-')
	{
		flag->minus = true;
		flag->zero = false;
	}
	else if (tmp_flag == '0' && !flag->minus)
		flag->zero = true;
	else if (tmp_flag == '#')
		flag->hash = true;
	else if (tmp_flag == '.')
	{
		flag->dot = true;
		tmp = flag->precision;
	}
	else if (tmp_flag == '+')
		flag->plus = true;
	else if (tmp_flag == ' ')
		flag->space = true;
	*tmp = flag_nbr_insert(format);
}

bool	flag_check(const char **format, t_flag *flag)
{
	while (**format)
	{
		if (is_specifier(**format))
			return (true);
		else if (is_flag(**format))
			flag_insert(format, flag);
		(*format)++;
	}
	return (false);
}
