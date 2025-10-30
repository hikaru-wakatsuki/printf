/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/30 09:02:02 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

bool	c_specifier(int content, int *count, t_flag *flag)
{
	if (flag->width || !flag->minus)
	{
		if (!c_flag_output(flag->width, count))
			return (false);
	}
	if (!ft_putchar_printf((char)content, count))
		return (false);
	if (flag->minus)
	{
		if (!c_flag_output(flag->width, count))
			return (false);
	}
	return (true);
}

bool	s_specifier(char *content, int *count, t_flag *flag)
{
	int	n;

	if (!content)
	{
		if (!ft_putstr_printf("(null)", count))
			return (false);
		return (true);
	}
	n = ft_strlen(content);
	if (flag->dot)
		n = flag->precision;
	if (flag->width > n && !flag->minus)
	{
		if (!s_flag_output(flag->width - n, count))
			return (false);
	}
	if (!ft_putnstr_printf(content, count, n))
		return (false);
	if (flag->width > n && flag->minus)
	{
		if (!s_flag_output(flag->width - n, count))
			return (false);
	}
	return (true);
}

bool	p_specifier(void *content, int *count, t_flag *flag)
{
	char		*buffer;
	uintptr_t	ptr;
	int			n;

	ptr = (uintptr_t)content;
	if (!ptr)
	{
		if (!ft_putstr_printf("(nil)", count))
			return (false);
		return (true);
	}
	buffer = itoa_ubase(ptr, "0123456789abcdef");
	if (!buffer)
		return (false);
	n = ft_strlen(buffer);
	if (flag->dot)
		n = flag->precision;
	if (flag->width > n + 2 && flag->minus)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putstr_printf("0x", count))
		return (false);
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!p_zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	di_specifier(int content, int *count, t_flag *flag)
{
	char		*buffer;
	intptr_t	ptr;
	int			n;

	ptr = (intptr_t)content;
	buffer = itoa_base(ptr, "0123456789");
	if (!buffer)
		return (false);
	n = ft_strlen(buffer);
	if (flag->dot && flag->precision > n)
		n = flag->precision;
	if (flag->width > n + 2 && flag->minus)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	if (flag->plus || flag->space)
	{
		if (flag->plus)
		{
			if (!ft_putchar_printf('+', count))
				return (false);
		}
		else
		{
			if (!ft_putchar_printf(' ', count))
				return (false);
		}
	}
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!p_zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!(!content && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, n))
			return (false);
	}
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	u_specifier(unsigned int content, int *count, t_flag *flag)
{
	char		*buffer;
	uintptr_t	ptr;
	int			n;

	ptr = (uintptr_t)content;
	buffer = itoa_ubase(ptr, "0123456789");
	if (!buffer)
		return (false);
	n = ft_strlen(buffer);
	if (flag->dot && flag->precision > n)
		n = flag->precision;
	if (flag->width > n + 2 && flag->minus)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!p_zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!(!content && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, n))
			return (false);
	}
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	x_specifier(unsigned int content, const char sp, int *count,
		t_flag *flag)
{
	char	*buffer;
	int			n;

	if (sp == 'x')
		buffer = itoa_ubase(content, "0123456789abcdef");
	else
		buffer = itoa_ubase(content, "0123456789ABCDEF");
	if (!buffer)
		return (false);
	n = ft_strlen(buffer);
	if (flag->dot)
		n = flag->precision;
	if (flag->width > n + 2 && flag->minus)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putstr_printf("0x", count))
		return (false);
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!p_zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!p_space_output(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	parcent_specifier(int *count, t_flag *flag)
{
	if (!ft_putchar_printf('%', count))
		return (false);
	return (true);
}

static bool	print_specifier(const char sp, va_list ap, int *count, t_flag *flag)
{
	bool	is_print;

	is_print = 0;
	if (sp == 'c')
		is_print = c_specifier((char)va_arg(ap, int), count, flag);
	else if (sp == 's')
		is_print = s_specifier(va_arg(ap, char *), count, flag);
	else if (sp == 'p')
		is_print = p_specifier(va_arg(ap, void *), count, flag);
	else if (sp == 'd' || sp == 'i')
		is_print = di_specifier(va_arg(ap, int), count, flag);
	else if (sp == 'u')
		is_print = u_specifier(va_arg(ap, unsigned int), count, flag);
	else if (sp == 'x' || sp == 'X')
		is_print = x_specifier(va_arg(ap, unsigned int), sp, count, flag);
	else if (sp == '%')
		is_print = ft_putchar_printf(count, flag);
	if (!is_print)
		return (false);
	return (true);
}
