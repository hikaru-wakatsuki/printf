/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 21:16:51 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

bool	c_specifier(int content, int *count, t_flag *flag)
{
	if (!ft_putchar_printf((char)content, count))
		return (false);
	return (true);
}

bool	s_specifier(char *content, int *count, t_flag *flag)
{
	if (!content)
	{
		if (!ft_putstr_printf("(null)", count))
			return (false);
		return (true);
	}
	if (!ft_putstr_printf(content, count))
		return (false);
	return (true);
}

bool	p_specifier(void *content, int *count, t_flag *flag)
{
	char		*buffer;
	uintptr_t	ptr;

	ptr = (uintptr_t)content;
	if (!ptr)
	{
		if (!ft_putstr_printf("(nil)", count))
			return (false);
		return (true);
	}
	buffer = itoa_base(ptr, "0123456789abcdef");
	if (!buffer)
		return (false);
	if (!ft_putstr_printf("0x", count))
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}

bool	di_specifier(int content, int *count, t_flag *flag)
{
	if (!ft_putnbr_printf(content, count))
		return (false);
	return (true);
}

bool	u_specifier(unsigned int content, int *count, t_flag *flag)
{
	if (!ft_unsigned_putnbr_printf(content, count))
		return (false);
	return (true);
}

bool	x_specifier(unsigned int content, const char sp, int *count,
		t_flag *flag)
{
	char	*buffer;

	if (sp == 'x')
		buffer = itoa_base(content, "0123456789abcdef");
	else
		buffer = itoa_base(content, "0123456789ABCDEF");
	if (!buffer)
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}

bool	parcent_specifier(int *count, t_flag *flag)
{
	if (!ft_putchar_printf(('%', count)))
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
		is_print = u_specifier(va_arg(ap, unsigned int), count,
				flag);
	else if (sp == 'x' || sp == 'X')
		is_print = x_specifier(va_arg(ap, unsigned int), sp, count, flag);
	else if (sp == '%')
		is_print = ft_putchar_printf(count, flag);
	if (!is_print)
		return (false);
	return (true);
}
