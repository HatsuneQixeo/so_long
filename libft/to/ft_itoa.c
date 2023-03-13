/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:30:57 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/08 21:30:59 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	ft_digit_count(uintptr_t nbr)
{
	int	digit;

	digit = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

static char	*itoa_core(unsigned int nbr, char sign)
{
	char	*str;
	int		digit;

	digit = ft_digit_count(nbr);
	str = malloc(digit + sign + 1);
	str[digit + sign] = 0;
	while (digit--)
	{
		str[digit + sign] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (itoa_core(-n, 1));
	else
		return (itoa_core(n, 0));
}
