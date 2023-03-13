/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_axis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:59:00 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:02 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_axis	ft_vector(t_axis unit, t_axis target)
{
	return ((t_axis){target.x - unit.x, target.y - unit.y});
}

t_list	*ft_lstnew_uaxis(t_axis i)
{
	t_uaxis	*uaxis;

	uaxis = malloc(sizeof(t_uaxis));
	uaxis->axis = i;
	uaxis->nextmove = i;
	uaxis->vector = 1;
	return (ft_lstnew(uaxis));
}

//Remove the axis in uaxis matching the coordinate of position
//and Reconnect the list
void	ft_terminate(t_list **uaxis, t_axis position)
{
	t_uaxis	*cmp;
	t_list	*finder;
	t_list	*connector;

	finder = *uaxis;
	cmp = finder->content;
	if (!ft_axiscmp(cmp->axis, position))
	{
		*uaxis = (*uaxis)->next;
		ft_lstdelone(finder, free);
		return ;
	}
	while (finder->next)
	{
		cmp = finder->next->content;
		if (!ft_axiscmp(cmp->axis, position))
		{
			connector = finder->next;
			finder->next = connector->next;
			ft_lstdelone(connector, free);
			return ;
		}
		finder = finder->next;
	}
	debug_axis(position, "Termination Failed", 0);
}
