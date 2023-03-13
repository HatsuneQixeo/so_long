/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:08:15 by hqixeo            #+#    #+#             */
/*   Updated: 2022/10/07 19:08:15 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	len;
	size_t	len_to_find;

	if (!*to_find)
		return ((char *)str);
	len = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	while (*str && len-- >= len_to_find)
		if (!ft_strncmp(str++, to_find, len_to_find))
			return ((char *)--str);
	return (0);
}
