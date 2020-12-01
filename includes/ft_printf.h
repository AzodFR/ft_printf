/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:48:49 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/01 16:53:39 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

typedef struct          s_flags
{
    int     minus;
    int     zero;
    int     dot;
    int     star;
}                       t_flags;
int     ft_printf(const char *format, ...) __attribute__ ((format(printf,1,2)));
#endif