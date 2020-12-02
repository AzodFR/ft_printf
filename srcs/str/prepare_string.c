/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:40:39 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 16:47:56 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prepare_string(const char *format, va_list ap, int *ret)
{
	int		i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i = convert(format, ap, i, ret);
		else
		{
			ft_putstr_fd((char *)&format[i], 1);
			*ret += 1;
		}
	}
}