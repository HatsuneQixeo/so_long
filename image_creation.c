/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:58:27 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/24 22:03:55 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//Note: len is default as the index (does not need n * sizeof(int))
void	ft_intset(unsigned int *ptr, unsigned int set, size_t len)
{
	while (len--)
		ptr[len] = set;
}

void	ft_mlx_colourfill(t_data data, unsigned int colour,
			t_axis start, t_axis end)
{
	void	*ptr;
	size_t	len;

	if (start.x >= end.x || start.y >= end.y)
		return ;
	ptr = data.address + (start.y * data.size_line) + (start.x * sizeof(int));
	len = end.x - start.x;
	start.y--;
	while (++start.y < end.y)
	{
		ft_intset(ptr, colour, len);
		ptr += data.size_line;
	}
}

//Create a PIXEL size image with given colour
//with opaque border and some transparency within
//Note: Border is opaque regardless of the given colour value
t_image	*ft_mlx_create_ptr(void *mlx, unsigned int colour)
{
	t_image	*pointer;
	int		border;
	t_data	data_ptr;

	pointer = malloc(sizeof(t_image));
	pointer->width = PIXEL;
	pointer->height = PIXEL;
	pointer->mlx = mlx_new_image(mlx, PIXEL, PIXEL);
	colour %= VALUE_T;
	border = PIXEL / 12;
	data_ptr = ft_data_address(pointer);
	ft_mlx_colourfill(data_ptr, colour,
		(t_axis){0, 0}, (t_axis){PIXEL, PIXEL});
	ft_mlx_colourfill(data_ptr, colour + (unsigned int)VALUE_T * 180,
		(t_axis){border, border}, (t_axis){PIXEL - border, PIXEL - border});
	return (pointer);
}

// t_image	*ft_mlx_create_colour_tile(void *mlx, unsigned int colour,
// 			unsigned int colour_border, t_range )
// {
// 	t_image	*pointer;
// 	int		border;
// 	t_data	data_ptr;

// 	pointer = malloc(sizeof(t_image));
// 	pointer->width = PIXEL;
// 	pointer->height = PIXEL;
// 	pointer->mlx = mlx_new_image(mlx, PIXEL, PIXEL);
// 	colour %= VALUE_T;
// 	border = PIXEL / 12;
// 	data_ptr = ft_data_address(pointer);
// 	ft_mlx_colourfill(data_ptr, colour,
// 		(t_axis){0, 0}, (t_axis){PIXEL, PIXEL});
// 	ft_mlx_colourfill(data_ptr, colour + (unsigned int)VALUE_T * 180,
// 		(t_axis){border, border}, (t_axis){PIXEL - border, PIXEL - border});
// 	return (pointer);
// }

static void	ft_mlx_draw_map(t_game *g, t_data data_map)
{
	t_data	data_space;
	t_data	data_ui;
	t_data	data_wall;
	t_axis	i;

	data_space = ft_data_address(g->map.space);
	data_wall = ft_data_address(g->map.wall);
	data_ui = ft_data_address(g->map.ui);
	ft_mlx_imgfill(data_map, data_ui, (t_axis){0, 0},
		(t_axis){g->map.size.x, BAR_HEIGHT});
	ft_mlx_imgfill(data_map, data_space, (t_axis){0, BAR_HEIGHT},
		(t_axis){g->map.size.x, g->map.size.y + BAR_HEIGHT});
	i.y = BAR_HEIGHT - 1;
	while (++i.y < BAR_HEIGHT + g->map.size.y)
	{
		i.x = -1;
		while (++i.x < g->map.size.x)
			if (g->map.structure[i.y - BAR_HEIGHT][i.x] == '1')
				ft_mlx_imgcpy(data_map, data_wall, i);
	}
}

t_image	*ft_map_image(t_game *g)
{
	t_image	*map;

	map = malloc(sizeof(t_image));
	map->width = g->map.size.x * PIXEL;
	map->height = (g->map.size.y + BAR_HEIGHT) * PIXEL;
	g->win = mlx_new_window(g->mlx, map->width, map->height, "So_long");
	map->mlx = mlx_new_image(g->mlx, map->width, map->height);
	ft_mlx_draw_map(g, ft_data_address(map));
	return (map);
}
