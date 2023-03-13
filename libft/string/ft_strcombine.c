/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:40:45 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/08 18:40:47 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strcombine(char *str1, char *str2)
{
	char	*str_main;

	str_main = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str_main);
}
