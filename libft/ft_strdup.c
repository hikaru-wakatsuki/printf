/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:22:44 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/22 19:59:21 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*dup;

	s_len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dup)
		return (NULL);
	dup[s_len] = '\0';
	while (*s)
		*(dup++) = *(s++);
	dup -= s_len;
	return (dup);
}
