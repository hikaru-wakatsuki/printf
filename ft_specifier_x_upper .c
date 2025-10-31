/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x_upper .c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:28:47 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:37:04 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	hash_print(unsigned int content, int *count, t_flag *flag,
		char *buffer)
{
	if (flag->hash && content)
	{
		if (!ft_putstr_printf("0X", count))
		{
			free(buffer);
			return (false);
		}
	}
	return (true);
}

bool	x_upper_specifier(unsigned int content, int *count, t_flag *flag)
{
	char	*buffer;
	int		digits;

	buffer = itoa_ubase((uintptr_t)content, "0123456789ABCDEF");
	if (!buffer)
		return (false);
	digits = flag_strlen(content, buffer, flag);
	if (!x_before_print(content, count, flag, buffer))
		return (false);
	if (!(!content && flag->dot && !flag->precision))
	{
		if (!ft_putnstr_printf(buffer, count, digits))
		{
			free(buffer);
			return (false);
		}
	}
	if (!x_minus_print(content, count, flag, buffer))
		return (false);
	free(buffer);
	return (true);
}
