/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 09:15:03 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

bool	c_specifier(int content, int *count, t_flag *flag)
{
	if (flag->width > 1 && !flag->minus)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	if (!ft_putchar_printf((char)content, count))
		return (false);
	if (flag->width > 1 && flag->minus)
	{
		if (!space_print(flag->width - 1, count))
			return (false);
	}
	return (true);
}

static bool	s_null(int *count, t_flag *flag)
{
	if (flag->width > 6 && !flag->minus)
	{
		if (!space_print(flag->width - 6, count))
			return (false);
	}
	if (!ft_putstr_printf("(null)", count))
		return (false);
	if (flag->width > 6 && flag->minus)
	{
		if (!space_print(flag->width - 6, count))
			return (false);
	}
	return (true);
}

bool	s_specifier(char *content, int *count, t_flag *flag)
{
	int	n;

	if (!content)
		return (s_null(count, flag));
	else
		n = ft_strlen(content);
	if (flag->dot && flag->precision < n)
		n = flag->precision;
	if (flag->width > n && !flag->minus)
	{
		if (!space_print(flag->width - n, count))
			return (false);
	}
	if (!ft_putnstr_printf(content, count, n))
		return (false);
	if (flag->width > n && flag->minus)
	{
		if (!space_print(flag->width - n, count))
			return (false);
	}
	return (true);
}

static bool	p_nil(int *count, t_flag *flag)
{
	if (flag->width > 5 && !flag->minus)
	{
		if (!space_print(flag->width - 5, count))
			return (false);
	}
	if (!ft_putstr_printf("(nil)", count))
		return (false);
	if (flag->width > 5 && flag->minus)
	{
		if (!space_print(flag->width - 5, count))
			return (false);
	}
	return (true);
}

bool	p_print(char *buffer, int *count, t_flag *flag)
{
	int	n;

	n = ft_strlen(buffer);
	if (flag->width > n + 2 && !flag->minus)
	{
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putstr_printf("0x", count))
		return (false);
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && flag->minus)
	{
		if (!space_print(flag->width - n - 2, count))
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
		return (p_nil(count, flag));
	buffer = itoa_base(ptr, "0123456789abcdef");
	if (!buffer)
		return (false);
	if (!p_print(buffer, count, flag))
		return (false);
	free(buffer);
	return (true);
}
bool	di_sign_print(int content, int *count, t_flag *flag, char *buffer)
{
	if (content < 0)
	{
		if (!ft_putchar_printf('-', count))
		{
			free(buffer);
			return (false);
		}
	}
	else if (flag->plus)
	{
		if (!ft_putchar_printf('+', count))
		{
			free(buffer);
			return (false);
		}
	}
	else if (flag->space)
	{
		if (!ft_putchar_printf(' ', count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

static int	is_sign(int content, t_flag *flag)
{
	return (content < 0 || flag->plus || flag->space);
}

bool	di_width_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;

	digits = ft_strlen(buffer);
	sign = is_sign(content, flag);
	width = 0;
	if (flag->width > digits + sign && !flag->minus && (!flag->zero
			|| flag->dot))
	{
		if (flag->precision > digits)
			width = flag->width - flag->precision - sign;
		else
			width = flag->width - digits - sign;
		if (!space_print(width, count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	di_minus_print(int content, int *count, t_flag *flag, char *buffer)
{
	int	width;
	int	sign;
	int	digits;

	digits = ft_strlen(buffer);
	sign = is_sign(content, flag);
	width = 0;
	if (flag->width + sign > digits && flag->minus)
	{
		if (flag->precision > digits)
			width = flag->width - flag->precision - sign;
		else
			width = flag->width - digits - sign;
		if (!space_print(width, count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	di_specifier(int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;
	long	tmp;
	int		sign;

	tmp = (long)content;
	if (content < 0)
		tmp *= -1;
	sign = is_sign(content, flag);
	buffer = itoa_base((uintptr_t)tmp, "0123456789");
	if (!buffer)
		return (false);
	digits = ft_strlen(buffer);
	// if (flag->dot && flag->width > n && flag->minus && flag->zero)
	if (!di_width_print(content, count, flag, buffer))
		return (false);
	if (!di_sign_print(content, count, flag, buffer))
		return (false);
	if (flag->width > digits && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print(flag->width - digits - sign, count))
			return (false);
	}
	if (flag->precision > digits && flag->dot)
	{
		if (!zero_print(flag->precision - digits, count))
			return (false);
	}
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
			return (false);
	}
	if (!di_minus_print(content, count, flag, buffer))
		return (false);
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
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!(!content && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, n))
			return (false);
	}
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	x_specifier(unsigned int content, const char sp, int *count,
		t_flag *flag)
{
	char	*buffer;
	int		n;

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
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	if (flag->hash && sp == 'x')
	{
		if (!ft_putstr_printf("0x", count))
			return (false);
	}
	else
	{
		if (!ft_putstr_printf("0X", count))
			return (false);
	}
	if (flag->width > n + 2 && !flag->dot && !flag->minus && flag->zero)
	{
		if (!zero_print(flag->width - n - 2, count))
			return (false);
	}
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && !flag->minus && !flag->zero)
	{
		if (!space_print(flag->width - n - 2, count))
			return (false);
	}
	free(buffer);
	return (true);
}

bool	parcent_specifier(int *count, t_flag *flag)
{
	if (flag->width || !flag->minus || !flag->zero)
	{
		if (!space_print(flag->width, count))
			return (false);
	}
	if (!flag->minus || flag->zero)
	{
		if (!zero_print(flag->width, count))
			return (false);
	}
	if (!ft_putchar_printf('%', count))
		return (false);
	return (true);
	if (flag->minus)
	{
		if (!space_print(flag->width, count))
			return (false);
	}
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
