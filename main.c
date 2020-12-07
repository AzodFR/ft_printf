/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:36 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/06 20:07:34 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int		ret;
	int ret2;

	ret = ft_printf("%s%d%p%x%X%i%%%c", "salut a toi", 999, &ret, 96547, 96547, 666, '?');
	printf("\n------------\n");
	ret2 = printf("%s%d%p%x%X%i%%%c", "salut a toi", 999, &ret, 96547, 96547, 666, '?');
	printf("\n------------\n");
	printf("[%d] [%d]\n", ret, ret2);
    return (0);
}
