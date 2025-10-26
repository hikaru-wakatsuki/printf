/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/25 16:51:41 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

bool	is_valid_printf(const char **format, void *content)
{

}

void	flag_check(const char flag, void *content, int sign)
{
	if (flag == '-')
		flag_space();
	else if (flag == '0')
		flag_zero();
	else if (flag == '.')
		flag_period();
	else if (flag == '#')
		flag_hash();
	else if (flag == '+')

	else if (flag == ' ')

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
			if (!is_valid_printf(&format, va_arg(ap, void *)))
				return (0);
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		++format;
	}
	va_end(ap);
	return (1);
}
