/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:36:46 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 18:31:55 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_noprec(t_flags flags, int numb, int len)
{
	int		ret;
	int		ws;

	ret = 0;
	ws = flags.len;
	if (!flags.minus && ws > len)
	{
		ws -= len - (numb < 0);
		if (flags.zero && numb < 0 && (numb *= -1) > 0)
		{
			ws--;
			ft_putchar_len('-');
		}
		while (ws--)
			ret += ft_putchar_len(flags.zero ? '0' : ' ');
	}
	ft_putnbr_fd(numb, 1);
	if (flags.minus && ws > len)
	{
		ws -= len;
		
		while (ws--)
			ret += ft_putchar_len(' ');
	}
	return (ret);
}

int		print_prec(t_flags flags, int numb, int len)
{
	int		zeros;
	int		ws;
	int		abs;
	int		ret;

	zeros = flags.len < 0 ? flags.dot : flags.dot - len + (numb < 0);
	ws = flags.len > flags.dot ? flags.len - zeros - len : 0;
	abs = numb < 0 ? numb * -1 : numb;
	ret = 0;
	while (0 < ws--)
		ret += ft_putchar_len(' ');
	if (numb < 0)
		ft_putchar_len('-');
	while (0 < zeros--)
		ret += ft_putchar_len('0');
	ft_putnbr_fd(abs, 1);
	return (ret);
}

int		convert_d_i(va_list ap, t_flags flags)
{
	int		numb;
	int		ret;

	numb = va_arg(ap, int);
	ret = ft_digitlen(numb);
	if (!haveflags(flags))
		ft_putnbr_fd(numb, 1);
	else
	{
		if (flags.dot < 0)
			ret += print_noprec(flags, numb, ret);
		else
			ret += print_prec(flags, numb, ret);
	}
	return (ret);
}