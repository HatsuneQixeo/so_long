/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:29:45 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/10 18:29:47 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putendl_fd(const char *str, int fd)
{
	if (str)
		return (ft_strrelease_fd(ft_strjoin(str, "\n"), fd));
	return (0);
}
