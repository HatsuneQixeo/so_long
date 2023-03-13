/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:23:47 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/04 14:23:48 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_digit_count_base(uintptr_t un_n, int len_base)
{
	int	digit;

	digit = 1;
	while (un_n / len_base)
	{
		un_n /= len_base;
		digit++;
	}
	return (digit);
}

static int	ft_str_dupchr(const char *base)
{
	base--;
	while (*++base)
		if (ft_strchr(base + 1, *base))
			return (*base);
	return (0);
}

char	*ft_utoa_base(uintptr_t un_n, const char *base)
{
	char			*str;
	size_t			array;
	size_t			len_base;

	if (ft_strlen(base) < 2 || ft_str_dupchr(base))
		return (0);
	len_base = ft_strlen(base);
	array = ft_digit_count_base(un_n, len_base);
	str = malloc(array + 1);
	if (!str)
		return (0);
	str[array] = 0;
	while (array--)
	{
		str[array] = base[un_n % len_base];
		un_n /= len_base;
	}
	return (str);
}
