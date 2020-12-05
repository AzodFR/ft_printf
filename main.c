/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:36 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/05 01:07:30 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int		ret;
	int ret2;

	ret = ft_printf("%p", (void *)ULONG_MAX);
	printf("\n------------\n");
	ret2 = printf("%p", (void *)ULONG_MAX);
	printf("\n------------\n");
	printf("[%d] [%d]\n", ret, ret2);
    return (0);
}
