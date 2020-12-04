/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:36 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/04 22:46:10 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int		ret;
	int ret2;

	ret = ft_printf("%011x", UINT_MAX);
	printf("\n------------\n");
	ret2 = printf("%011x", UINT_MAX);
	printf("\n------------\n");
	printf("[%d] [%d]\n", ret, ret2);
    return (0);
}
