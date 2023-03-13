/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:58:19 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:58:22 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static t_axis	ft_prio_hrz(t_axis zombie, t_axis vector, int prio)
{
	if (prio == 0)
		zombie.x += ft_direction(vector.x);
	else if (prio == 1)
		zombie.y += ft_direction(vector.y);
	else if (prio == 2)
		zombie.y += -ft_direction(vector.y);
	else if (prio == 3)
		zombie.x += -ft_direction(vector.x);
	return (zombie);
}

static t_axis	ft_prio_vrt(t_axis zombie, t_axis vector, int prio)
{
	if (prio == 0)
		zombie.y += ft_direction(vector.y);
	else if (prio == 1)
		zombie.x += ft_direction(vector.x);
	else if (prio == 2)
		zombie.x += -ft_direction(vector.x);
	else if (prio == 3)
		zombie.y += -ft_direction(vector.y);
	return (zombie);
}

static t_axis	ft_prio(t_map map, t_uaxis *zombie, t_axis vector, int prio)
{
	t_axis	move;

	if (vector.y + vector.x == 0 || prio == 4)
		return (zombie->nextmove);
	if (ft_abs(vector.x) <= ft_abs(vector.y))
		move = ft_prio_vrt(zombie->nextmove, vector, prio);
	else
		move = ft_prio_hrz(zombie->nextmove, vector, prio);
	if (!ft_axiscmp(zombie->axis, move))
		return (ft_prio(map, zombie, vector, ++prio));
	else if (ft_uaxisaxis(map.zombie.lst_uaxis, move, ft_getaxis)
		&& ft_uaxisaxis(map.zombie.lst_uaxis, move, ft_getnextmove))
		return (zombie->nextmove);
	else if (map.structure[move.y][move.x] == '1'
		|| ft_uaxisaxis(map.collectible.lst_uaxis, move, ft_getaxis)
		|| ft_uaxisaxis(map.exit.lst_uaxis, move, ft_getaxis)
		|| ft_uaxisaxis(map.zombie.lst_uaxis, move, ft_getnextmove))
		return (ft_prio(map, zombie, vector, ++prio));
	return (move);
}

t_axis	ft_nearesttarget(t_axis unit, t_list *target)
{
	t_axis	near;
	t_axis	cmp;

	near = ft_vector(unit, ft_getaxis(target->content));
	target = target->next;
	while (target)
	{
		cmp = ft_vector(unit, ft_getaxis(target->content));
		if (ft_abs_sumaxis(cmp) < ft_abs_sumaxis(near))
			near = cmp;
		target = target->next;
	}
	return (near);
}

void	ft_pathfind(t_game *g, t_list *lst_zombie, t_list *lst_player)
{
	t_axis	move;
	t_uaxis	*zombie;

	if (!lst_player)
		return ;
	while (lst_zombie)
	{
		zombie = lst_zombie->content;
		move = ft_prio(g->map, zombie,
				ft_nearesttarget(zombie->axis, lst_player), 0);
		ft_facing(zombie, zombie->nextmove.x - zombie->axis.x);
		zombie->axis = zombie->nextmove;
		zombie->nextmove = move;
		lst_zombie = lst_zombie->next;
	}
}
