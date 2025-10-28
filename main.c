/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:54:02 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 18:10:12 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *str = NULL;
	// char c = 'c';
	int i;
	int j;

	// i = 0x100;
	// j = i;
	i = ft_printf("ft_print = %s\n", str);
	ft_printf("%d\n", i);
	j = printf("   print = %s\n", str);
	printf("%d\n", j);

}
