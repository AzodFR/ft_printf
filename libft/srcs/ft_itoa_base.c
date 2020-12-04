/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:05:06 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 18:16:02 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int	n, char *base)
{
	char			*res;
	int				i;
	int				base_size;
	unsigned int	u_n;

	if (!(res = malloc(8 * sizeof(char))))
		return (NULL);
	base_size = ft_strlen(base);
	i = 0;
	if (n > 0)
	{
		while (n)
		{
			res[i++] = base[n % base_size];
			n /= base_size;
		}
	}
	else
	{
		u_n = n;
		while (u_n)
		{
			res[i++] = base[u_n % base_size];
			u_n /= base_size;
		}
	}
	return (res);
}
