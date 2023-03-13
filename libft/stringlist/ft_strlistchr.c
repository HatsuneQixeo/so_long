/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlistchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:11:32 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 20:11:34 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strlistchr(char **strlist, char c)
{
	char	*str;

	if (!strlist)
		return (0);
	while (*strlist)
	{
		str = ft_strchr(*strlist++, c);
		if (str)
			return (str);
	}
	return (0);
}
