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

uint8_t	transparent_value(uint16_t newTransparency)
{
	static uint8_t	transparency = 180;

	if ((newTransparency & ~0xFF) == 0) /* So Cursed */
		transparency = newTransparency;
	return (transparency);
}

void	img_colour_invert(void *img)
{
	t_data			data = ft_data_address(img);
	uint32_t		*address = (uint32_t *)data.address;
	const size_t	length = data.size / sizeof(uint32_t);

	for (unsigned int i = 0; i < length; i++)
	{
		uint32_t	value_a = (address[i]) & A_MASK;

		if (value_a == A_MASK)
			continue ;
		address[i] = ~address[i];
		address[i] &= ~A_MASK;
		address[i] |= value_a;
	}
}

void	iter_transparentize(void *image)
{
	ft_img_transparentize(ft_data_address(image), transparent_value(UINT16_MAX));
}

static void	ft_sprite(t_game *g)
{
	g->map.space = ft_image_xpm(g->mlx, "sprites/Tile/Marble_tile48.xpm");
	ft_img_transparentize(ft_data_address(g->map.space), 180);
	g->map.wall = ft_image_xpm(g->mlx, "sprites/Tile/Wall48.xpm");
	ft_img_transparentize(ft_data_address(g->map.wall), 180);
	g->map.collectible.lst_img = ft_image_newlst(g, "sprites/Collect/ - xpmlist.txt");
	g->map.player.lst_img = ft_image_newlst(g, "sprites/Player/ - xpmlist.txt");
	g->map.zombie.lst_img = ft_image_newlst(g, "sprites/Zombie/ - xpmlist.txt");
	g->map.exit.lst_img = ft_image_newlst(g, "sprites/Portal/ - xpmlist.txt");
	transparent_value(145);
	ft_lstiter(g->map.exit.lst_img, iter_transparentize);
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

	ft_bzero(&map, sizeof(t_map));
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
