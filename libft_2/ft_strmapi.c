/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:41:17 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/23 21:17:54 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	index;
	size_t			s_len;

	s_len = ft_strlen(s);
	map = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!map)
		return (NULL);
	index = 0;
	while (s[index])
	{
		map[index] = f(index, s[index]);
		index++;
	}
	map[index] = '\0';
	return (map);
}
