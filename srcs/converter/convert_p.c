/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:41:19 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 22:31:26 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_puthex(unsigned char c)
{
	return ((c > 9) ? 'a' + c - 10 : 48 + c);
}

int		ft_printaddr(unsigned long addr)
{
	int				i;
	int				ret;
	int				start;
	char			c;

	i = 3;
	ret = ft_putstr_len("0x");
	start = 1;
	while (++i < 16)
	{
		c = ft_puthex((addr >> 4 * (16 - i - 1)) % 16);
		if (start && c == '0')
			continue;
		if (!ft_isalnum(c))
			break;
		else
		{
			start = 0;
			ret += ft_putchar_len(c);
		}

	}
	return (ret);
}

int		apply_Pwhitespace(t_flags flags, unsigned long addr)
{
	int		ret;
	int		ws;

	ret = 0;
	ws = flags.len > 14 ? flags.len - 14: 0;
	if (!flags.minus)
		while (ws--)
			ret += ft_putchar_len(' ');
	ret += ft_printaddr(addr);
	if (flags.minus)
		while (ws--)
			ret += ft_putchar_len(' ');
	return (ret);
}

int		convert_p(va_list ap, t_flags flags)
{
	unsigned long	addr;

	addr = va_arg(ap, unsigned long);
	if (!haveflags(flags))
		return (ft_printaddr(addr));
	return (apply_Pwhitespace(flags, addr));
}
