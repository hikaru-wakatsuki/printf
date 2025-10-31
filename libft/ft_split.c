/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:14:31 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/26 13:03:17 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char const c)
{
	size_t	count;
	size_t	n;

	count = 0;
	n = 0;
	while (*s)
	{
		if (*s == c && n != 0)
		{
			count++;
			n = 0;
		}
		else if (*s != c)
			n++;
		s++;
	}
	if (n != 0)
		count++;
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	s_len;
	size_t	i;
	char	*dup;

	s_len = ft_strlen(s);
	if (n > s_len)
		n = s_len;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	dup[n] = '\0';
	i = 0;
	while (*s && i < n)
	{
		*(dup++) = *(s++);
		i++;
	}
	dup -= n;
	return (dup);
}

static bool	insert_word(char const *s, char **to_split, size_t to_index,
		size_t n)
{
	to_split[to_index] = ft_strndup(s - n, n);
	if (!(to_split[to_index]))
	{
		while (to_index--)
			free(to_split[(to_index)]);
		free(to_split);
		return (false);
	}
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**to_split;
	size_t	n;
	size_t	to_index;

	to_split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!to_split)
		return (NULL);
	n = 0;
	to_index = 0;
	while (*s)
	{
		if (*s == c && n != 0)
		{
			if (!(insert_word(s, to_split, (to_index++), n)))
				return (NULL);
			n = 0;
		}
		else if (*(s++) != c)
			n++;
	}
	if (n != 0)
		if (!(insert_word(s, to_split, (to_index++), n)))
			return (NULL);
	to_split[to_index] = NULL;
	return (to_split);
}
