/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:09:13 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/27 20:09:15 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_shout(const char *str)
{
	char	*cap;

	cap = ft_strmapi(str, ft_mapi_upper);
	ft_printf("(%s)\n", cap);
	free(cap);
}

void	ft_shownb(char *name, long long int nb)
{
	ft_printf("%s: %d\n", name, nb);
}

void	ft_show_rgba(void *ptr, size_t size)
{
	uint8_t	*str;
	size_t	i;
	size_t	pixel;

	pixel = 1;
	str = (uint8_t *)ptr;
	size /= 4;
	while (size--)
	{
		i = 4;
		ft_printf("pixel(%4d):", pixel++);
		while (i--)
			ft_printf(" [%d]", *str++);
		ft_printf("\n");
	}
}
