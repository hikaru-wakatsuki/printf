/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 22:16:15 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

bool	p_specifier(void *content, int *count)
{
	char		*buffer;
	intptr_t	ptr;

	ptr = (intptr_t)content;
	buffer = itoa_base(ptr, "0123456789abcde");
	if (!buffer)
		return (false);
	if (!ft_putstr_printf("0x\0", count))
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}

bool	x_specifier(char *content, const char flag, int *count)
{
	char	*buffer;

	buffer = itoa_base_unsigned(*(unsigned int *)(content), flag, 16);
	if (!buffer)
		return (false);
	if (!ft_putstr_printf(buffer, count))
		return (false);
	free(buffer);
	return (true);
}
