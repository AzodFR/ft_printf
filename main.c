/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:36 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/06 13:20:48 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int		ret;
	int ret2;

	ret = ft_printf("%.2s",NULL);
	printf("\n------------\n");
	ret2 = printf("%.2s", NULL);
	printf("\n------------\n");
	printf("[%d] [%d]\n", ret, ret2);
    return (0);
}
