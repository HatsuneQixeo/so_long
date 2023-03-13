/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:29 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:57:38 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static t_list	*ft_image_newlst(t_game *g, char *filelist)
{
	t_list	*lst_img;
	char	**list;
	size_t	y;

	y = 0;
	lst_img = 0;
	list = ft_file_extract_split(filelist);
	while (list[y])
		ft_lstadd_back(&lst_img, ft_lstnew(ft_image_xpm(g->mlx, list[y++])));
	ft_clear_strlist(list);
	return (lst_img);
}

void	ft_img_transparentize(t_data data, uint8_t transparency);

static void	ft_sprite(t_game *g)
{
	g->map.space = ft_image_xpm(g->mlx, "sprites/Tile/Marble_tile48.xpm");
	ft_img_transparentize(ft_data_address(g->map.space), 180);
	// g->map.space = ft_mlx_create_ptr(g->mlx, ft_get_colour(0, 0, 0, 0));
	g->map.wall = ft_image_xpm(g->mlx, "sprites/Tile/Wall48.xpm");
	ft_img_transparentize(ft_data_address(g->map.wall), 180);
	g->map.collectible.lst_img = ft_lstnew
		(ft_image_xpm(g->mlx, "sprites/Collect/leek48.xpm"));
	g->map.player.lst_img = ft_image_newlst(g, "sprites/Player/ - xpmlist.txt");
	g->map.zombie.lst_img = ft_image_newlst(g, "sprites/Zombie/ - xpmlist.txt");
	g->map.exit.lst_img = ft_image_newlst(g, "sprites/Portal/ - xpmlist.txt");
	g->map.ui = ft_mlx_create_ptr(g->mlx, ft_get_colour(50, 100, 100, 0));
	if (g->map.space == NULL)
		ft_exit("Error\nMissing xpm for space");
	else if (g->map.wall == NULL)
		ft_exit("Error\nMissing xpm for wall");
	else if (g->map.collectible.lst_img == NULL)
		ft_exit("Error\nMissing xpm for collectible");
	else if (g->map.player.lst_img == NULL)
		ft_exit("Error\nMissing xpm for player");
	else if (g->map.zombie.lst_img == NULL)
		ft_exit("Error\nMissing xpm for zombie");
	else if (g->map.exit.lst_img == NULL)
		ft_exit("Error\nMissing xpm for exit");
	else if (g->map.ui == NULL)
		ft_exit("Error\nSomething went wrong in creating image for ui");
	g->map.e_ptr = ft_mlx_create_ptr(g->mlx, ft_get_colour(0, 255, 0, 0));
	g->map.p_ptr = ft_mlx_create_ptr(g->mlx, ft_get_colour(0, 180, 200, 0));
	g->map.z_ptr = ft_mlx_create_ptr(g->mlx, ft_get_colour(255, 0, 0, 0));
}

static t_map	ft_map_extract(char *file_map)
{
	t_map	map;

	map.structure = 0;
	map.space = 0;
	map.wall = 0;
	map.player.lst_uaxis = 0;
	map.player.lst_img = 0;
	map.zombie.lst_uaxis = 0;
	map.zombie.lst_img = 0;
	map.collectible.lst_uaxis = 0;
	map.collectible.lst_img = 0;
	map.exit.lst_uaxis = 0;
	map.exit.lst_img = 0;
	map.p_ptr = 0;
	map.z_ptr = 0;
	map.ui = 0;
	map.e_ptr = 0;
	if (!ft_file_format(file_map, ".ber"))
		ft_exit(0);
	map.structure = ft_file_extract_lst(file_map);
	if (!map.structure)
		ft_exit("Empty Map");
	else if (!**map.structure)
		ft_error_map(map, "Map starts with nl", 0);
	return (ft_map_evaluate(map));
}

t_game	topdown(char *file_map)
{
	t_game	g;

	g.map = ft_map_extract(file_map);
	g.mlx = mlx_init();
	ft_sprite(&g);
	g.map.map_img = ft_map_image(&g);
	g.total_move = 0;
	g.frame = 0;
	return (g);
}
