/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:59:25 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:26 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//Return -1 if x is negative
//Return 1 if x is either positive or zero
int	ft_direction(int x)
{
	if (x < 0)
		return (-1);
	else
		return (1);
}

//Return the positive value of nb
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

//Return the sumed positive value of vector x and y
size_t	ft_abs_sumaxis(t_axis vector)
{
	return (ft_abs(vector.x) + ft_abs(vector.y));
}

int	mlx_offset_invert(size_t axis, int size)
{
	return (((axis * PIXEL) - (size - PIXEL)));
}

int	mlx_offset_centered(size_t axis, int size)
{
	return ((axis * PIXEL) - ((size - PIXEL) / 2));
}
