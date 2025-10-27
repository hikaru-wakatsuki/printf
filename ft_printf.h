/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 22:26:02 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi_base(const char *nptr);
char	*itoa_base(intptr_t n, char *base);
char	*itoa_base_unsigned(unsigned int n, const char flag, unsigned int base);
int		ft_printf(const char *format, ...);
bool	ft_putnbr_printf(int n, int *count);
bool	p_specifier(void *content, int *count);
bool	x_specifier(char *content, const char flag, int *count);
bool	ft_unsigned_putnbr_printf(unsigned int un, int *count);
bool	ft_putstr_printf(char *s, int *count);
bool	ft_putchar_printf(char c, int *count);

#endif
