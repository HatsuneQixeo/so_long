/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:57:17 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 19:57:19 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *str, unsigned int home, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (home >= str_len || !len)
		return (ft_strdup(""));
	str_len -= home;
	if (len > str_len)
		len = str_len;
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	ft_strlcpy(substr, str + home, len + 1);
	return (substr);
}
