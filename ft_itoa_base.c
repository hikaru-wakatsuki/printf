/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:23:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 18:58:56 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long	n_count(long nb, long base)
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
		nb /= base;
		count++;
	}
	return (count + sign);
}

static char	convert_base(long mod)
{
	if (mod == 10)
		return ('a');
	else if (mod == 11)
		return ('b');
	else if (mod == 12)
		return ('c');
	else if (mod == 13)
		return ('d');
	else if (mod == 14)
		return ('e');
	else if (mod == 15)
		return ('f');
	return ((char)(mod + '0'));
}


char	*itoa_base(int n, long base)
{
	char	*str;
	long	nb;
	long	index;

	nb = (long)n;
	index = n_count(nb, base);
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
		str[index] = convert_base(nb % base);
		nb /= base;
		index--;
	}
	return (str);
}
