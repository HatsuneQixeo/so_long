/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:56:42 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 19:56:43 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src) + 1;
	str = malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, src, len);
	return (str);
}
