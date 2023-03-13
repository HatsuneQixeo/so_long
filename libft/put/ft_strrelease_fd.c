/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrelease_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:04:10 by hqixeo            #+#    #+#             */
/*   Updated: 2022/10/06 20:04:11 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strrelease_fd(char *str, int fd)
{
	int	len;

	len = ft_putstr_fd(str, fd);
	free(str);
	return (len);
}
