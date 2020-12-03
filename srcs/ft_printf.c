/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:51:34 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 09:33:11 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list ap;

	ret = 0;
	va_start(ap,format);
	if (!read_format(format, ap))
		return (print_direct(format));
	ret = prepare_string(format, ap);
	va_end(ap);
	return (ret);
}