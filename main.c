/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:36 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/03 18:29:50 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int		ret;
	int ret2;
    

	ret = ft_printf("%*.5d\n",-6,-42);
	printf("------------\n");
	ret2 = printf("%*.5d\n",-6,-42);
	printf("------------\n");
	printf("[%d] [%d]\n", ret-1, ret2-1);
    return (0);
}