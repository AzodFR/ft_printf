/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrchr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:45:34 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/02 12:18:02 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrchr_fd(char *s, char c, int fd)
{
	if (fd < 0 || !s)
		return ;
	while(*s)
	{
		if (*s == c)
			return;
		write(fd, &(*s), 1);
		s++;
	}
}