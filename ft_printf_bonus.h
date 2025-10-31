/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/31 19:26:09 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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

bool	space_print(int flag_count, int *count);
bool	zero_print(int flag_count, int *count);
bool	space_print_malloc(int flag_count, int *count, char *buffer);
bool	zero_print_malloc(int flag_count, int *count, char *buffer);
#endif
