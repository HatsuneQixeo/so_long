/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlistdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:46:04 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/07 18:46:04 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_strlistdup(char **strlist)
{
	char	**strlist_main;
	size_t	i_str;

	i_str = ft_strcount(strlist);
	strlist_main = malloc(sizeof(char *) * (i_str + 1));
	strlist_main[i_str] = 0;
	while (i_str--)
		strlist_main[i_str] = ft_strdup(strlist[i_str]);
	return (strlist_main);
}
