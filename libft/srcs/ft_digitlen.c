/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:35:02 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 15:35:36 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlen(int n)
{
	unsigned int	nb;
	int				i;

	i = 1;
	nb = n;
	if (n < 0)
	{
		i = 2;
		nb = -n;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}