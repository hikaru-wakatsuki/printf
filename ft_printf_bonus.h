/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/10/28 03:53:58 by hwakatsu         ###   ########.fr       */
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
	int		precision;
	bool	dot;
}			t_flag;

#endif
