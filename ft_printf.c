/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/24 21:42:24 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

// int	count_n_and_one(const char *format, const char n)
// {
// 	int	i;

// 	i = 0;
// 	while (*format)
// 	{
// 		if (*format == n)
// 		{
// 			i++;
// 			format++;
// 		}
// 		format++;
// 	}
// 	return (i);
// }

bool	is_valid_flag(const char flag, void *content)
{

}

int	ft_printf(const char *format, ...)
{
	char	flag;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			flag = *(++format);
			if (is_valid_flag(flag, va_arg(ap, void *)))
				return (0);
		}
		++format;
	}
	va_end(ap);
	return (1);
}
