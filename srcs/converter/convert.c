/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:44:55 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 18:32:45 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_a_converter(char c)
{
	return (c == 'c' || c == 's' ||
			c == 'p' ||
			c == 'd' || c == 'i' ||
			c == 'u' ||
			c == 'x' || c == 'X' ||
			c == '%');
}

int convert (va_list ap, int i, t_flags flags)
{
	if (flags.type == 'c')
		i = convert_c(ap, flags);
	else if (flags.type == 's')
		i = convert_s(ap, flags);
	else if (flags.type == 'd' || flags.type == 'i')
		i = convert_d_i(ap, flags);
	/*else if (flags.type == 'p')
	else if (flags.type == 'u')
	else if (flags.type == 'x')
	else if (flags.type == 'X')*/
	else if (flags.type == '%')
		i = convert_perc(flags);
	return (i);
}