/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 17:50:47 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	s_specifier(char *content, int *count)
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

bool	p_specifier(void *content, int *count)
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

bool	x_specifier(unsigned int content, const char flag, int *count)
{
	char		*buffer;

	if (flag == 'x')
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
