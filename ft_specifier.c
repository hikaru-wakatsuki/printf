/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 03:57:02 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	p_specifier(void *content, int *count)
{
	char		*buffer;
	intptr_t	ptr;

	ptr = (intptr_t)content;
	buffer = itoa_base(ptr, "0123456789abcdef");
	if (!buffer)
		return (false);
	if (!ft_putstr_printf("0x\0", count))
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}

bool	x_specifier(void *content, const char flag, int *count)
{
	char		*buffer;
	intptr_t	ptr;

	ptr = (intptr_t)content;
	if (flag == 'x')
		buffer = itoa_base(ptr, "0123456789abcdef");
	else if (flag == 'X')
		buffer = itoa_base(ptr, "0123456789ABCDEF");
	if (!buffer)
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}
