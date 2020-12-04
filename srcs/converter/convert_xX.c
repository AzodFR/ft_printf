/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:24:46 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 20:04:54 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_xX(va_list ap, t_flags flags, int small)
{
	int		numb;
	char	*str;
	int		ret;

	ret = 0;
	numb = va_arg(ap, unsigned int);
	str = ft_itoa_base(numb, small ? "0123456789abcdef" : "0123456789ABCDEF");
	if (!str)
		return (0);
	if (!haveflags(flags))
		ret += ft_putstr_len(str);
	else
	{
		if (flags.dot == 0 && numb == 0)
		{
			while (flags.len--)
				ret += ft_putchar_len(' ');
		}
		else if (flags.len)
			ret = apply_whitespace(str, flags);
		else
			ret = ft_putstr_len(str);
	}
	free(str);
	return (ret);
}
