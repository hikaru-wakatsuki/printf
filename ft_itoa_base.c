/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:23:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 22:23:11 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intptr_t	n_count(intptr_t nb, intptr_t base_len)
{
	intptr_t	sign;
	intptr_t	count;

	sign = 0;
	if (nb <= 0)
		sign = 1;
	else if (nb > 0)
		nb *= -1;
	count = 0;
	while (nb < 0)
	{
		nb /= base_len;
		count++;
	}
	return (count + sign);
}

char	*itoa_base(intptr_t n, char *base)
{
	char		*str;
	intptr_t	base_len;
	intptr_t	index;

	base_len = (intptr_t)ft_strlen(base);
	index = n_count(n, base_len);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[(index--)] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else if (n > 0)
		n *= -1;
	while (n < 0)
	{
		str[index] = base[n * (-1) % base_len];
		n /= base_len;
		index--;
	}
	return (str);
}
