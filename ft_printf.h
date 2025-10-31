/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 23:38:57 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	bool	minus;
	bool	zero;
	bool	hash;
	bool	plus;
	bool	space;
	int		width;
	bool	dot;
	int		precision;
}			t_flag;

// space_zero_print.c
bool		space_print(int flag_count, int *count);
bool		zero_print(int flag_count, int *count);
bool		space_print_malloc(int flag_count, int *count, char *buffer);
bool		zero_print_malloc(int flag_count, int *count, char *buffer);
// ft_specifier.c
bool		c_specifier(int content, int *count, t_flag *flag);
bool		s_specifier(char *content, int *count, t_flag *flag);
bool		p_specifier(void *content, int *count, t_flag *flag);
bool		di_specifier(int content, int *count, t_flag *flag);
bool		u_specifier(unsigned int content, int *count, t_flag *flag);
bool		x_specifier(unsigned int content, int *count, t_flag *flag);
bool		x_upper_specifier(unsigned int content, int *count, t_flag *flag);
bool		per_specifier(int *count, t_flag *flag);
// ft_specifier_helper.c
bool		x_width_print(unsigned int content, int *count, t_flag *flag,
				char *buffer);
bool		x_minus_print(unsigned int content, int *count, t_flag *flag,
				char *buffer);
bool		x_before_print(unsigned int content, int *count, t_flag *flag,
				char *buffer);
int			flag_strlen(int content, char *buffer, t_flag *flag);


char		*itoa_base(uintptr_t n, char *base);
int			ft_printf(const char *format, ...);
bool		ft_putnbr_printf(int n, int *count);
bool		ft_unsigned_putnbr_printf(unsigned int un, int *count);
bool		ft_putstr_printf(char *s, int *count);
bool		ft_putchar_printf(char c, int *count);

#endif
