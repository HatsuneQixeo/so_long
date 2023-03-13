/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:59:22 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:23 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_facing(t_uaxis *unit, size_t x)
{
	if (x)
		unit->vector = x;
}

int	ft_mlx_static(size_t axis, int size)
{
	(void)size;
	return (((axis * PIXEL)));
}

void	ft_mlx_image(t_game *g, t_image *image, t_axis i, t_axis *offset)
{
	if (image == NULL)
		debug_axis(i, "Invalid image at: ", 0);
	else if (offset)
		mlx_put_image_to_window(g->mlx, g->win, image->mlx,
			ft_mlx_centered(i.x, image->width + offset->x),
			ft_mlx_invert(BAR_HEIGHT + i.y, image->height + offset->y));
	else
		mlx_put_image_to_window(g->mlx, g->win, image->mlx,
			ft_mlx_centered(i.x, image->width),
			ft_mlx_invert(BAR_HEIGHT + i.y, image->height));
}

void	ft_mlx_entityptr(t_game *g, t_image *image, t_list *lst_uaxis,
			t_axis (get)(t_uaxis *uaxis))
{
	int		serialnum;
	t_axis	i;

	serialnum = 0;
	while (lst_uaxis)
	{
		i = get(lst_uaxis->content);
		ft_mlx_image(g, image, i, 0);
		ft_mlxnbr(g, ++serialnum, &i);
		lst_uaxis = lst_uaxis->next;
	}
}

void	ft_mlx_entity(t_game *g, t_list *lst_img, t_list *lst_uaxis,
			t_axis *offset)
{
	int		serialnum;
	t_uaxis	*unit;

	serialnum = 0;
	while (lst_uaxis)
	{
		unit = lst_uaxis->content;
		if (unit->vector == -1 && (lst_img && lst_img->next))
			ft_mlx_image(g, lst_img->next->content, unit->axis, offset);
		else if (lst_img)
			ft_mlx_image(g, lst_img->content, unit->axis, offset);
		ft_mlxnbr(g, ++serialnum, &unit->axis);
		lst_uaxis = lst_uaxis->next;
	}
}

void	ft_mlxnbr(t_game *g, size_t nb, t_axis *axis)
{
	char	*str;

	if (!axis)
	{
		str = ft_strmodify(ft_itoa(nb), "Move:", ft_strrjoin);
		mlx_string_put(g->mlx, g->win, 0, 0, 0xc896, str);
	}
	else
	{
		str = ft_itoa(nb);
		mlx_string_put(g->mlx, g->win,
			axis->x * PIXEL, (BAR_HEIGHT + axis->y) * PIXEL, 0x32c8c8, str);
	}
	free(str);
}
