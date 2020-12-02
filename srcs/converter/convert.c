/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:44:55 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 16:49:26 by thjacque         ###   ########lyon.fr   */
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

char	get_convert_type(const char *format, int start)
{
	int		i;

	i = -1;
	while (format[++i])
		if (is_a_converter(format[i]))
			return (format[i]);
	return (0);
}

int		convert(const char *format, va_list ap, int start, int *ret)
{
	char	type;
	t_flags flags;

	type = get_convert_type(format, start);
	flags = initstruct(format, start, type);
	return (start);
}