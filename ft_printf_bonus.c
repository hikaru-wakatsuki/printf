/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 20:50:13 by hwakatsu         ###   ########.fr       */
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
	flag->minus = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->width = 0;
	flag->dot = 0;
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

void	flag_insert(const char **format, t_flag *flag)
{
	int		*tmp;
	char	tmp_flag;

	tmp_flag = **format;
	(*format)++;
	if (tmp_flag == '-')
		tmp = flag->minus;
	else if (tmp_flag == '0')
		tmp = flag->zero;
	else if (tmp_flag == '#')
		tmp = flag->hash;
	else if (tmp_flag == '.')
		tmp = flag->dot;
	else if (tmp_flag == '+')
		tmp = flag->plus;
	else if (tmp_flag == ' ')
		tmp = flag->space;
	else if ('0' <= tmp_flag && tmp_flag <= '9')
		tmp = flag->width;
	while ('0' <= **format && **format <= '9')
	{
		*tmp *= 10;
		*tmp += **format - '0';
		(*format)++;
	}
}

bool	flag_check(const char **format, t_flag *flag)
{
	int		*tmp;
	char	tmp_flag;

	while (**format)
	{
		if (is_specifier(**format))
			return (true);
		else if (is_flag(**format))
			flag_insert(format, flag);
		else
			(*format)++;
	}
	return (false);
}
