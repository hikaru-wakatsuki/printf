/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:23:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 18:08:21 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static uintptr_t	n_count(uintptr_t nb, uintptr_t base_len)
{
	uintptr_t	sign;
	uintptr_t	count;

	sign = 0;
	if (nb == 0)
		sign = 1;
	count = 0;
	while (nb)
	{
		nb /= base_len;
		count++;
	}
	return (count + sign);
}

char	*itoa_base(uintptr_t n, char *base)
{
	char		*str;
	uintptr_t	base_len;
	uintptr_t	index;

	base_len = (uintptr_t)ft_strlen(base);
	index = n_count(n, base_len);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[(index--)] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[index] = base[n % base_len];
		n /= base_len;
		index--;
	}
	return (str);
}
