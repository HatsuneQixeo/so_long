/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_axisfind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:59:04 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:06 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// Return a value if the axis does not match
int	ft_axiscmp(t_axis axis1, t_axis axis2)
{
	return (!(axis1.y == axis2.y && axis1.x == axis2.x));
}

//Return axis in the given uaxis
t_axis	ft_getaxis(t_uaxis *uaxis)
{
	return (uaxis->axis);
}

//Return nextmove in the given uaxis
t_axis	ft_getnextmove(t_uaxis *uaxis)
{
	return (uaxis->nextmove);
}

//Find the coordinate that matches to_find in axislst
//Return the matching coordinate inside lst
t_list	*ft_uaxisaxis(t_list *lst, t_axis to_find, t_get get)
{
	while (lst)
	{
		if (!ft_axiscmp(get(lst->content), to_find))
			break ;
		lst = lst->next;
	}
	return (lst);
}

//Find any matching coordinate between two axislst
//Return the matching coordinate from the second list
t_list	*ft_uaxisuaxis(t_list *lst, t_list *to_find,
		t_get get_lst, t_get get_tofind)
{
	while (to_find)
	{
		if (ft_uaxisaxis(lst, get_tofind(to_find->content), get_lst))
			break ;
		to_find = to_find->next;
	}
	return (to_find);
}
