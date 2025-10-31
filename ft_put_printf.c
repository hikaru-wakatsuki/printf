/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:47:39 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 20:05:57 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_putchar_printf(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (false);
	(*count)++;
	return (true);
}

bool	ft_putstr_printf(char *s, int *count)
{
	while (*s)
	{
		if (write(1, (s++), 1) == -1)
			return (false);
		(*count)++;
	}
	return (true);
}

bool	ft_putnstr_printf(char *s, int *count, int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		if (write(1, &s[i], 1) == -1)
			return (false);
		(*count)++;
		i++;
	}
	return (true);
}
