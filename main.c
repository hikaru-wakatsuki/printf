/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:54:02 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 21:07:24 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	// char str[] = "0xabcde\0";
	// char c = 'c';
	int i;

	i = 0x100;
	// i = ft_printf("ft_print = %i\n", i);
	// ft_printf("%d\n", i);
	i = printf("   print = %i\n", i);
	printf("%d\n", i);

}
