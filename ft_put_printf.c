/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:47:39 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 19:21:06 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

bool	ft_putnbr_printf(int n, int *count)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		if (!ft_putchar_printf('-', &count))
			return (false);
		nb *= -1;
	}
	if (nb >= 10)
	{
		if (!ft_putchar_printf((int)(nb / 10), &count))
			return (false);
	}
	if (!ft_putchar_printf((nb % 10) + '0', &count))
		return (false);
	return (true);
}

bool	ft_putstr_printf(char *s, int *count)
{
	while (*s)
	{
		if (write(1, (s++), 1) == -1)
			return (false);
		count++;
	}
	return (true);
}

bool	ft_putchar_printf(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (false);
	count++;
	return (true);
}
