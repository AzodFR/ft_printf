/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:41:19 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 23:21:52 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_p(va_list ap, t_flags flags)
{
	unsigned long long		addr;
	char					*str;
	int						ret;

	addr = va_arg(ap, unsigned long long);
	str = ft_ulltoa_base(addr, 16);
	ret = 0;
	if (!haveflags(flags))
		return (ft_putstr_len(str));
	if (flags.len)
		ret += apply_whitespace(str, flags);
	else
		ret += ft_putstr_len(str);
	free(str);
	return (ret);
}
