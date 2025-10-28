/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:10:36 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/22 19:50:56 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb >= INT_MAX / size)
		return (NULL);
	cal = malloc(nmemb * size);
	if (!cal)
		return (NULL);
	ft_bzero(cal, nmemb * size);
	return (cal);
}
