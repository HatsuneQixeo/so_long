/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:41 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:57:44 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_collide(t_game *g, t_list *unit, t_axis to, t_axis direction)
{
	while (ft_uaxisaxis(unit, to, ft_getaxis))
		to = (t_axis){to.x + direction.x, to.y + direction.y};
	return (g->map.structure[to.y][to.x] == '1');
}

static void	ft_move(t_game *g, t_uaxis *player, t_axis direction)
{
	t_axis	to;

	ft_facing(player, direction.x);
	to = (t_axis){direction.x + player->axis.x, direction.y + player->axis.y};
	if (!g->map.collectible.lst_uaxis
		&& ft_uaxisaxis(g->map.exit.lst_uaxis, to, ft_getaxis))
		ft_exit("Game Cleared\n");
	else if (ft_collide(g, g->map.player.lst_uaxis, to, direction))
		return ;
	else if (ft_uaxisaxis(g->map.collectible.lst_uaxis, to, ft_getaxis))
	{
		ft_terminate(&g->map.collectible.lst_uaxis, to);
		if (!g->map.collectible.lst_uaxis)
			ft_printf("MIKU IS READY TO LEAVE\n");
	}
	player->axis = to;
	g->total_move++;
}

static void	ft_moveplayer(t_game *g, t_axis direction)
{
	t_list	*lst;

	lst = g->map.player.lst_uaxis;
	while (lst)
	{
		ft_move(g, lst->content, direction);
		lst = lst->next;
	}
}

int	ft_input(int key, t_game *g)
{
	t_axis	direction;

	direction = (t_axis){0, 0};
	ft_printf("key: %d\n", key);
	if (key == W)
		direction.y--;
	else if (key == A)
		direction.x--;
	else if (key == S)
		direction.y++;
	else if (key == D)
		direction.x++;
	else if (key == ESC)
		ft_close(g);
	else
		return (0);
	ft_moveplayer(g, direction);
	ft_update(g);
	return (1);
}
