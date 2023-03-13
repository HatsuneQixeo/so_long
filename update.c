/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:58:49 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:58:55 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//Hardcode talent
// static void	ft_breath(t_game *g, t_unit entity)
// {
// 	size_t	breath;
// 	size_t	section;
// 	size_t	inhale;
// 	t_axis	to;
// 	char	order;

// 	breath = PIXEL;
// 	section = breath / 8;
// 	inhale = (g->frame % (breath * (FPS / UPS))) / (FPS / UPS);
// 	order = 0;
// 	if (inhale < section * ++order)//1
// 		to.y = section / 2 + inhale;
// 	else if (inhale < section * ++order)//2
// 		to.y = section / 2 + inhale;
// 	else if (inhale < section * ++order)//3
// 		to.y = section * 3 + ((inhale - section * 3) / 2);
// 	else if (inhale < section * ++order)//4
// 		to.y = section * 3 + ((inhale - section * 3) / 2);
// 	else if (inhale < section * ++order)//5decend
// 		to.y = breath - (inhale + ((inhale - section * 3) / 2));
// 	else if (inhale < section * ++order)//6
// 		to.y = breath - (inhale + ((inhale - section * 3) / 2));
// 	else if (inhale < section * ++order)//7
// 		to.y = breath - (section * 7 + ((inhale - section * 5) / 2));
// 	else if (++order)//8
// 		to.y = (inhale - section * 7) / 2;
// 	to.x = 0;
// 	ft_mlx_entity(g, entity.lst_img, entity.lst_uaxis, &to);
// }

// Bit style
// static void	ft_breath(t_game *g, t_unit entity)
// {
// 	size_t	breath;
// 	size_t	inhale;
// 	size_t	section;
// 	t_axis	to;
// 	char	order;

// 	breath = PIXEL / 2;
// 	section = breath / 4;
// 	inhale = (g->frame % (breath * (FPS / UPS))) / (FPS / UPS);
// 	order = 0;
// 	if (inhale < section * ++order)
// 		to.y = breath / 4;
// 	else if (inhale < section * ++order)
// 		to.y = 0;
// 	else if (inhale < section * ++order)
// 		to.y = breath / 3;
// 	else
// 		to.y = 0;
// 	to.x = 0;
// 	ft_mlx_entity(g, entity.lst_img, entity.lst_uaxis, &to);
// }

// Bounce
static void	ft_breath(t_game *g, t_unit entity)
{
	size_t	breath;
	size_t	section;
	size_t	inhale;
	t_axis	offset;
	char	order;

	breath = PIXEL / 2;
	section = breath / 6;
	inhale = (g->frame % (breath * (FPS / UPS))) / (FPS / UPS);
	order = 0;
	if (inhale < section * ++order)
		offset.y = inhale;
	else if (inhale < section * ++order)
		offset.y = inhale;
	else if (inhale < section * ++order)
		offset.y = section * 2 + ((inhale - section * 2) / 2);
	else if (inhale < section * ++order)
		offset.y = breath - (section * 4 + ((inhale - section * 4) / 2));
	else if (inhale < section * ++order)
		offset.y = breath - inhale;
	else
		offset.y = breath - inhale;
	offset.x = 0;
	ft_mlx_entity(g, entity.lst_img, entity.lst_uaxis, &offset);
}

static void	ft_animate(t_game *g, t_unit entity)
{
	size_t	order;

	order = g->frame
		% (ft_lstsize(entity.lst_img) * ((FPS / UPS) * 2)) / (FPS / UPS) / 2;
	ft_mlx_entity(g, ft_lstselect(entity.lst_img, order), entity.lst_uaxis, 0);
}

static void	ft_infection(t_game *g)
{
	t_list	*target;

	target = ft_uaxisuaxis(g->map.player.lst_uaxis, g->map.zombie.lst_uaxis,
			ft_getaxis, ft_getaxis);
	while (target)
	{
		ft_lstadd_back(&g->map.zombie.lst_uaxis,
			ft_lstnew_uaxis(ft_getaxis(target->content)));
		ft_terminate(&g->map.player.lst_uaxis, ft_getaxis(target->content));
		target = ft_uaxisuaxis(g->map.player.lst_uaxis, target,
				ft_getaxis, ft_getaxis);
	}
}

void	ft_update(t_game *g)
{
	if (!g->map.player.lst_uaxis)
		ft_exit("Game Over\n");
	mlx_put_image_to_window(g->mlx, g->win, g->map.map_img->mlx, 0, 0);
	if (!g->map.collectible.lst_uaxis)
		ft_mlx_entityptr(g, g->map.e_ptr, g->map.exit.lst_uaxis, ft_getaxis);
	ft_mlx_entityptr(g, g->map.p_ptr, g->map.player.lst_uaxis, ft_getaxis);
	ft_mlx_entityptr(g, g->map.z_ptr, g->map.zombie.lst_uaxis, ft_getnextmove);
	ft_animate(g, g->map.exit);
	ft_breath(g, g->map.collectible);
	ft_breath(g, g->map.player);
	ft_breath(g, g->map.zombie);
	ft_mlxnbr(g, g->total_move, 0);
	ft_infection(g);
}
