/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:47:39 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 18:42:58 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putnbr_printf(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd((int)(nb / 10), fd);
	ft_putchar_fd((nb % 10) + '0', fd);
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
