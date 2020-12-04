/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:38:01 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 18:49:21 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_whitespace(char *str, t_flags flags)
{
	int		i;
	int		ws;
	int		len;

	i = 0;
	len = ft_strlen(str);
	ws = len ? flags.len - len : flags.len;
	if (!flags.minus && ws > 0)
		while (ws--)
			i += ft_putchar_len(flags.zero ? '0' : ' ');
	i += ft_putstr_len(str);
	if (flags.minus && ws > 0)
		while (ws--)
			i += ft_putchar_len(flags.zero ? '0' : ' ');
	return (i);
}

char	*apply_precision(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (i > -1 && i <= len)
		str[i] = 0;
	return (str);
}
int		convert_s(va_list ap, t_flags flags)
{
	int		ret;
	char	*str;

	ret = 0;
	if (!haveflags(flags))
		return (ft_putstr_len(va_arg(ap, char*)));
	str = ft_strdup(va_arg(ap, char*));
	str = apply_precision(str, flags.dot);
	if (flags.len)
		ret = apply_whitespace(str, flags);
	else
		ret = ft_putstr_len(str);
	free(str);
	return (ret);
}
