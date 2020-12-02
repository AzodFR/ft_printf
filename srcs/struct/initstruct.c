/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:30:10 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 16:49:21 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		initstruct(const char *f, int start, char type)
{
	t_flags		elem;

	elem.minus = get_minus(f, start, type);
	elem.zer = get_zero(f, start, type);
	elem.zer_len = elem.zer ? get_len(f, elem.zer) : 0;
	elem.dot = get_dot(f, start, type);
	elem.dot_len = elem.dot ? get_len(f, elem.dot) : 0;
	elem.nor = 0;
	elem.nor_len = 0;
	return (elem);
}