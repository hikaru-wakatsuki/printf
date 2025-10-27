/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/27 17:51:26 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

int		ft_atoi_base(const char *nptr);
char	*itoa_base(int n, long base);
char	*itoa_base_unsigned(unsigned int n, const char flag, unsigned int base);
bool	ft_putnbr_printf(int n, int *count);
bool	ft_unsigned_putnbr_printf(unsigned int un, int *count);
bool	ft_putstr_printf(char *s, int *count);
bool	ft_putchar_printf(char c, int *count);

#endif
