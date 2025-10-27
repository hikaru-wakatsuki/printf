/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 01:23:03 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 18:59:01 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned int	n_count(unsigned int n, unsigned int base)
{
	unsigned int	sign;
	unsigned int	count;

	sign = 0;
	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count + sign);
}

static char	lower_convert_base(unsigned int mod)
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

static char	upper_convert_base(unsigned int mod)
{
	if (mod == 10)
		return ('A');
	else if (mod == 11)
		return ('B');
	else if (mod == 12)
		return ('C');
	else if (mod == 13)
		return ('D');
	else if (mod == 14)
		return ('E');
	else if (mod == 15)
		return ('F');
	return ((char)(mod + '0'));
}

char	*itoa_base_unsigned(unsigned int n, const char flag, unsigned int base)
{
	char			*str;
	unsigned int	index;

	index = n_count(n, base);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[(index--)] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if (flag == 'x')
			str[index] = lower_convert_base(n % base);
		else if (flag == 'X')
			str[index] = upper_convert_base(n % base);
		n /= base;
		index--;
	}
	return (str);
}
