/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:05:06 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 18:23:02 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_positive(char *res, char *base, int n)
{
	int		i;
	int		base_size;

	i = 0;
	base_size = ft_strlen(base);
	while (n)
	{
		res[i++] = base[n % base_size];
		n /= base_size;
	}
	return (res);
}

char	*convert_negative(char *res, char *base, unsigned int n)
{
	int		i;
	int		base_size;

	i = 0;
	base_size = ft_strlen(base);
	while (n)
	{
		res[i++] = base[n % base_size];
		n /= base_size;
	}
	return (res);
}

char	*ft_itoa_base(int	n, char *base)
{
	char			*res;

	if (!(res = malloc(8 * sizeof(char))))
		return (NULL);
	if (n > 0)
		return (convert_positive(res, base, n));
	else
		return (convert_negative(res, base, n));
}
