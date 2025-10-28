/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 18:08:40 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*itoa_base(uintptr_t n, char *base);
int		ft_printf(const char *format, ...);
bool	ft_putnbr_printf(int n, int *count);
bool	s_specifier(char *content, int *count);
bool	p_specifier(void *content, int *count);
bool	x_specifier(unsigned int content, const char flag, int *count);
bool	ft_unsigned_putnbr_printf(unsigned int un, int *count);
bool	ft_putstr_printf(char *s, int *count);
bool	ft_putchar_printf(char c, int *count);

#endif
