/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:20:51 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 13:04:14 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (i);
	while (s[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strnlen(dst, size);
	src_len = ft_strlen(src);
	if (size > dest_len)
	{
		dst += dest_len;
		while (size > dest_len + 1 && *src)
		{
			*(dst++) = *(src++);
			size--;
		}
		*dst = '\0';
		return (dest_len + src_len);
	}
	else
		return (size + src_len);
}
