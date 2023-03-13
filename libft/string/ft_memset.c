/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:03:02 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/05 15:03:05 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Note: This funtion set the value byte by byte
//	that means it doesn't function properly if c contain value more than 1 byte
//	despite it asks for an integer value.
void	*ft_memset(void *ptr, int c, size_t bytes)
{
	char	*str;

	str = ptr;
	if (str)
		while (bytes--)
			*str++ = c;
	return (ptr);
}
