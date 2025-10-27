/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 07:43:05 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

char	*itoa_base(int n, long base);
int		ft_atoi_base(const char *nptr);
bool	ft_putnbr_printf(int n, int *count);
bool	ft_unsigned_putnbr_printf(unsigned int un, int *count);
bool	ft_putstr_printf(char *s, int *count);
bool	ft_putchar_printf(char c, int *count);

#endif
