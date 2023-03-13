/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlist_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:18:20 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/01 17:18:21 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstrlist_fd(char **strlist, int fd)
{
	int	len;

	len = 0;
	if (strlist)
		while (*strlist)
			len += ft_putendl_fd(*strlist++, fd);
	return (len);
}
