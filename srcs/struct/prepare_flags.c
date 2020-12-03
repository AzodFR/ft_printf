/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:46:08 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 14:28:23 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			haveflags(t_flags flags)
{
	return (flags.dot > -1 || flags.minus || flags.zero || flags.len || flags.star);
}

t_flags		prepare_flags(const char *format, va_list ap, int *i)
{
	t_flags		flags;
	int			j;

	flags = initstruct();
	j = *i;
	while (!is_a_converter(format[j]))
	{
		if (format[j] == '.')
			j = set_dot(format, &flags, j ,ap);
		if (format[j] == '*')
			j = set_star(&flags, j, ap);
		if (format[j] == '-')
			j = set_minus(&flags, j);
		if (format[j] == '0' && !flags.minus && !flags.len)
			j = set_zero(&flags, j);
		if (ft_isdigit(format[j]))
			j = set_len(format[j], &flags, j);
	}
	flags.type = format[j++];
	*i = j;
	return (flags);
}