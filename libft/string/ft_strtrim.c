/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:57:06 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 19:57:07 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *src, const char *set)
{
	char	*end;

	if (!src)
		return (0);
	else if (!set)
		return (ft_strdup(src));
	end = ft_strchr(src, 0) - 1;
	while (ft_strchr(set, *src) && src <= end)
		src++;
	while (ft_strchr(set, *end) && src < end)
		end--;
	return (ft_substr(src, 0, end - src + 1));
}
