/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus copy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 20:52:56 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

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

static bool	p_print(char *buffer, int *count, t_flag *flag)
{
	int	n;

	n = ft_strlen(buffer);
	if (flag->width > n + 2 && !flag->minus)
	{
		if (!space_print_malloc(flag->width - n - 2, count, buffer))
			return (false);
	}
	if (!ft_putstr_printf("0x", count))
		return (false);
	if (!ft_putnstr_printf(buffer, count, n))
		return (false);
	if (flag->width > n + 2 && flag->minus)
	{
		if (!space_print_malloc(flag->width - n - 2, count, buffer))
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
