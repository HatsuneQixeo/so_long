/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strliststr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:59:56 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/01 16:59:58 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strliststr(char **strlist, const char *str)
{
	char	*find;

	while (*strlist)
	{
		find = ft_strstr(*strlist++, str);
		if (find)
			return (find);
	}
	return (0);
}
