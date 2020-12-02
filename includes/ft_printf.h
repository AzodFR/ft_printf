/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:48:49 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 16:49:30 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_flags
{
	int		minus;
	int		zer;
	int		zer_len;
	int		dot;
	int		dot_len;
	int		nor;
	int		nor_len;
}					t_flags;

/*	GET NUMBER IN FLAGS */
int		get_len(const char *f, int start);
int		get_dot(const char *f, int start, char type);
int		get_minus(const char *f, int start, char type);
int		get_zero(const char *f, int start, char type);

/*	PREPARING THE CONVERTION */
void		prepare_string(const char *format, va_list ap, int *ret);
t_flags		initstruct(const char *f, int start, char c);
int			convert(const char *format, va_list ap, int start, int *ret);

/*	PRINT WITHOUT CONVERSION */
int			print_direct(const char *format);


/* KNOW IF THERE IS A CONVERSION */
int			read_format(const char *format, va_list ap);

/*	PRINTF */
int			ft_printf(const char *format, ...) __attribute__ ((format(printf,1,2)));
#endif