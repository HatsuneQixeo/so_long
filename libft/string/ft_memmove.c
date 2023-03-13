/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:02:54 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/05 15:02:57 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t bytes)
{
	char	*ptr_src;
	char	*ptr_dst;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (!dst || !src)
		return (0);
	if (dst > src)
		while (bytes--)
			ptr_dst[bytes] = ptr_src[bytes];
	else if (dst < src)
		while (bytes--)
			*ptr_dst++ = *ptr_src++;
	return (dst);
}
