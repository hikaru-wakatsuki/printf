/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 17:20:19 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include "ft_printf_bonus.h"

// static bool	is_valid_printf(const char **format, va_list ap, int *count)
// {
// 	while (**format)
// 	{
// 		if (is_specifier(**format))
// 		{
// 			if (print_specifier(**format, ap, count))
// 				return (true);
// 			else
// 				return (false);
// 		}
// 		(*format)++;
// 	}
// 	return (false);
// }
// t_flag	*flag_initialization(void)
// {
// 	t_flag	*flag;

// 	flag = (t_flag *)malloc(sizeof(flag) * 1);
// 	if (!flag)
// 		return (NULL);
// 	flag->minus = 0;
// 	flag->zero = 0;
// 	flag->hash = 0;
// 	flag->plus = 0;
// 	flag->space = 0;
// 	flag->width = 0;
// 	flag->dot = 0;
// 	return (flag);
// }
// t_flag	*flag_check(const char **format, va_list ap, int *count)
// {
// 	t_flag	*flag;

// 	flag = flag_initialization();
// 	if (!flag)
// 		return (NULL);
// 	if (flag == '-')
// 		flag_hyphon();
// 	else if (flag == '0')
// 		flag_zero();
// 	else if (flag == '.')
// 		flag_period();
// 	else if (flag == '#')
// 		flag_hash();
// 	else if (flag == '+')
// 		flag_plus();
// 	else if (flag == ' ')
// 		flag_space();
// }
