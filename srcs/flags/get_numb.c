/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:58:49 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 16:44:08 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(const char *f, int start)
{
	int		num;
	int		mult;

	mult = 1;
	num = 0;
	while (ft_isdigit(f[++start]))
	{
		num += (f[start] - '0') * mult;
		mult *= 10;
	}
	return (num);
}

int		get_dot(const char *f, int start, char type)
{
	while (f[++start] != type)
		if (f[start] == '.')
			return (start);
	return (0);
}
int		get_minus(const char *f, int start, char type)
{
	while (f[++start] != type)
		if (f[start] == '-')
			if (!ft_isdigit(f[start + 1]))
				return (start);
	return (0);
}

int		get_zero(const char *f, int start, char type)
{
	while (f[++start] != type)
		if (f[start] == '0')
			if (!ft_isdigit(f[start - 1]))
				return (start);
	return (0);
}