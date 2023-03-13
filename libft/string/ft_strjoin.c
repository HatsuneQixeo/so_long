/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:56:53 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 19:56:54 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str_main;
	size_t	len;

	if (!str1 && !str2)
		return (0);
	else if (!str1)
		return (ft_strdup(str2));
	else if (!str2)
		return (ft_strdup(str1));
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_main = malloc(len);
	if (!str_main)
		return (0);
	ft_strlcpy(str_main, str1, len);
	ft_strlcat(str_main, str2, len);
	return (str_main);
}

//Reverse str2 with str1, dedicated for strmodify
char	*ft_strrjoin(const char *str1, const char *str2)
{
	return (ft_strjoin(str2, str1));
}
