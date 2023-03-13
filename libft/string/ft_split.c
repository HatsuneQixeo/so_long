/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:56:23 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 19:56:24 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	trigger_counter(const char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		while (*str != c && *str)
			str++;
		if (*(str - 1) != c)
			counter++;
	}
	return (counter);
}

static char	**split(const char *str, char c, char **str_main)
{
	size_t	x;
	size_t	y;
	size_t	home;
	size_t	len;

	x = 0;
	y = 0;
	home = 0;
	len = ft_strlen(str);
	while (x < len)
	{
		while (str[x] == c)
			home = ++x;
		while (str[x] != c && x < len)
			++x;
		if (str[x] == c || (x == len && home != x))
			str_main[y++] = ft_substr(str, home, x - home);
	}
	str_main[y] = 0;
	return (str_main);
}

char	**ft_split(const char *str, char c)
{
	char	**str_main;

	if (!str)
		return (0);
	str_main = malloc(sizeof(char *) * (trigger_counter(str, c) + 1));
	if (!str_main)
		return (0);
	return (split(str, c, str_main));
}
