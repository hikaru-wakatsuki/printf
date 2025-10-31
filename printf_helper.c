/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 18:09:27 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_flag_char(char const flag)
{
	return (flag == '-' || flag == '0' || flag == '#' || flag == '+'
		|| flag == ' ');
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
