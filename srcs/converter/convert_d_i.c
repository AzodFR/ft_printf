/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:36:46 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 02:18:16 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cancer(t_flags flags, int numb)
{
	int		a;
	int		zeros;
	int		ws;
	int		ret;

	ret = 0;
	a = ft_digitlen(numb) - (numb < 0);
	if (flags.zero && flags.dot == -1)
		zeros = flags.len - a - (numb < 0) > 0 ? flags.len - a - (numb < 0): 0;
	else
		zeros = flags.dot - a > 0 ? flags.dot - a : 0;
	ws = flags.len - (zeros + a) - (numb < 0);
	ws = ws > 0 ? ws : 0;
	if (!flags.minus)
	{
		while (ws--)
			ret += ft_putchar_len(' ');
		if (numb < 0)
			ft_putchar_len('-');
	}
	if (flags.minus && numb < 0)
		ft_putchar_len('-');
	while (zeros--)
		ret += ft_putchar_len('0');
	if (numb < 0 && numb == -2147483648)
		ft_putunbr_fd(-numb, 1);
	else
		ft_putnbr_fd(numb < 0 ? -numb : numb, 1);
	if (flags.minus)
		while (ws--)
			ret+= ft_putchar_len(' ');
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
	else if (!flags.dot && numb == 0 && !(ret = 0))
		while (flags.len--)
			ret += ft_putchar_len(' ');
	else if (flags.zero && flags.minus)
	{
		if (numb < 0 && numb == -2147483648)
			ft_putunbr_fd(-numb, 1);
		else
			ft_putnbr_fd(numb < 0 ? -numb : numb, 1);
		flags.len -= ft_digitlen(numb);
		while (0 < flags.len--)
			ret += ft_putchar_len(' ');
	}
	else
		ret += ft_cancer(flags, numb);
	return (ret);
}