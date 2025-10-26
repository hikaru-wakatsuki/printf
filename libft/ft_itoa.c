/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:23:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/22 19:52:07 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	n_count(long nb)
{
	long	sign;
	long	count;

	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb *= -1;
	}
	else if (nb == 0)
		return (1);
	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count + sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	long	index;

	nb = n;
	index = n_count(nb);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[(index--)] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[index] = (nb % 10) + '0';
		nb /= 10;
		index--;
	}
	return (str);
}
