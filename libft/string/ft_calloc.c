/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:32:04 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/06 14:32:07 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*ptr;

	ptr = malloc(len * size);
	if (ptr)
		ft_bzero(ptr, len * size);
	return (ptr);
}
