/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnl_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:26:07 by hqixeo            #+#    #+#             */
/*   Updated: 2022/10/10 05:26:08 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnl_fd(int amount, int fd)
{
	char	*str_nl;

	if (!amount)
		return (0);
	else if (amount == 1)
		return (ft_putchar_fd('\n', fd));
	str_nl = malloc(amount + 1);
	if (!str_nl)
		return (0);
	str_nl[amount] = 0;
	return (ft_strrelease_fd(ft_memset(str_nl, '\n', amount), fd));
}
