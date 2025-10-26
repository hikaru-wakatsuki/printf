/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:21:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 19:29:24 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

bool	is_valid_printf(const char **format, void *content)
{
}

static bool	is_specifier(char const flag)
{
	if (flag == 'c')
		return (true);
	else if (flag == 's')
		return (true);
	else if (flag == 'p')
		return (true);
	else if (flag == 'd')
		return (true);
	else if (flag == 'i')
		return (true);
	else if (flag == 'u')
		return (true);
	else if (flag == 'x')
		return (true);
	else if (flag == 'X')
		return (true);
	else if (flag == '%')
		return (true);
	return (false);
}

void	is_specifier(const char flag, void *content, int sign)
{
	char	*buffer;

	if (flag == 'c')
		ft_putchar_fd((char)content, 1);
	else if (flag == 's')
		ft_putstr_fd((char *)content, 1);
	else if (flag == 'p')
	{
		buffer = itoa_base((int)(content), 16);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(buffer, 1);
		free(buffer);
	}
	else if (flag == 'd')
		ft_putnbr_fd((int)content, 1);
	else if (flag == 'i')
		i_specifier((char *)content);
	else if (flag == 'u')
			else if (flag == 'x')
				else if (flag == 'X')
					else if (flag == '%')
}

void	flag_check(const char flag, void *content, int sign)
{
	if (flag == '-')
		flag_hyphon();
	else if (flag == '0')
		flag_zero();
	else if (flag == '.')
		flag_period();
	else if (flag == '#')
		flag_hash();
	else if (flag == '+')
		flag_plus();
	else if (flag == ' ')
		flag_space();
}

int	ft_printf(const char *format, ...)
{
	char	flag;
	va_list	ap;
	int count;

	count = 0;
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
