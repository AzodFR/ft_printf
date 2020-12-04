/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:24:46 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 22:06:53 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		apply_xwhitespace(char *str, t_flags flags)
{
	int		i;
	int		ws;
	int		len;
	int		zeros;

	i = 0;
	len = ft_strlen(str);
	ws = 0;
	zeros = 0;
	zeros = len ? flags.dot - len : flags.dot;
	ws = len ? flags.len - len - zeros : flags.len - zeros;
	if (!flags.minus)
	{
		while (ws-- > 0)
			i += ft_putchar_len(flags.zero ? '0' : ' ');
		while (zeros-- > 0)
			i += ft_putchar_len('0');
	}
	i += ft_putstr_len(str);
	if (flags.minus)
		while (ws-- > 0)
			i += ft_putchar_len(flags.zero ? '0' : flags.dot ? '0' : ' ');
	return (i);
}

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
		else if (flags.len || flags.dot)
			ret = apply_xwhitespace(str, flags);
		else
			ret = ft_putstr_len(str);
	}
	free(str);
	return (ret);
}
