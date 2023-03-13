/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:35 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/06 14:35:39 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len_to_find;

	if (!*to_find)
		return ((char *)str);
	len_to_find = ft_strlen(to_find);
	while (*str && len-- >= len_to_find)
		if (!ft_strncmp(str++, to_find, len_to_find))
			return ((char *)--str);
	return (0);
}
