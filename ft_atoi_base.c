/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:43:29 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 18:24:17 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	hexadecimal_to_decimal(const char *nptr)
{
	long	nbr;

	nbr = 0;
	while (('0' <= *nptr && *nptr <= '9') || ('a' <= *nptr && *nptr <= 'f'))
	{
		if ('0' <= *nptr && *nptr <= '9')
		{
			nbr *= 16;
			nbr += (long)(*nptr - '0');
		}
		else if ('a' <= *nptr && *nptr <= 'f')
		{
			nbr *= 16;
			nbr += (long)(*nptr - 'a' + 10);
		}
		nptr++;
	}
	return (nbr);
}

long	octal_to_decimal(const char *nptr)
{
	long	nbr;

	nbr = 0;
	while ('0' <= *nptr && *nptr <= '8')
	{
		nbr *= 8;
		nbr += (long)(*nptr - '0');
		nptr++;
	}
	return (nbr);
}

long	decimal_conversion(const char *nptr, long base)
{
	long	nbr;

	nbr = 0;
	if (base == 16)
	{
		nbr = hexadecimal_to_decimal(nptr);
	}
	else if (base == 8)
	{
		nbr = octal_to_decimal(nptr);
	}
	else
	{
		while ('0' <= *nptr && *nptr <= '9')
		{
			nbr *= 10;
			nbr += (long)(*nptr - '0');
			nptr++;
		}
	}
	return (nbr);
}

int	ft_atoi_base(const char *nptr)
{
	long	sign;
	long	nbr;

	while ((9 <= *nptr && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (*nptr == '0')
	{
		if (*(++nptr) == 'x')
		{
			nbr = decimal_conversion(++nptr, 16);
		}
		else
			nbr = decimal_conversion(nptr, 8);
	}
	else
		nbr = decimal_conversion(nptr, 10);
	return ((int)(sign * nbr));
}
