/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:29:15 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/23 21:17:24 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	unsigned char	uc;
	size_t			i;

	ub = (unsigned char *)b;
	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ub[(i++)] = uc;
	}
	return (b);
}
