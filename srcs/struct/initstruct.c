/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:30:10 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 12:16:53 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		initstruct(void)
{
	t_flags		elem;

	elem.minus = 0;
	elem.zero = 0;
	elem.dot = -1;
	elem.star = 0;
	elem.len = 0;
	elem.type = 0;
	return (elem);
}