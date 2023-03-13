/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:54:31 by hqixeo            #+#    #+#             */
/*   Updated: 2022/08/05 14:54:32 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strskipchr(char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}

char	*ft_strcreate(char set, size_t size)
{
	char	*str;

	if (!size)
		return (0);
	str = malloc(size + 1);
	str[size] = 0;
	return (ft_memset(str, set, size));
}

char	*ft_strfill(char *str, char set, int len_add, t_ftstr ft_str)
{
	char	*str_c;

	if (len_add <= 0)
		return (str);
	str_c = ft_strcreate(set, len_add);
	str = ft_strmodify(str, str_c, ft_str);
	free(str_c);
	return (str);
}

void	ft_swapchar(char *sign, char *set)
{
	char	tmp;

	tmp = *sign;
	*sign = *set;
	*set = tmp;
}
