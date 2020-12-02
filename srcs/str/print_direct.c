/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:41:59 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 10:47:12 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_direct(const char *format)
{
	int		ret;

	ret = ft_strlen(format);
	write(1, format, ret);
	return (ret);
}