/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_evaluate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:58:03 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:39 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_map_unit(t_map map)
{
	if (!map.player.lst_uaxis)
		ft_error_map(map, "Missing player", 0);
	else if (!map.collectible.lst_uaxis)
		ft_error_map(map, "Missing collectible", 0);
	else if (!map.exit.lst_uaxis)
		ft_error_map(map, "Missing exit", 0);
	// if (map.player.lst_uaxis->next)
	// {
	// 	ft_printf("Error\n");
	// 	debug_entity(map.player.lst_uaxis->next, "Duplicate Player");
	// 	ft_exit(0);
	// }
	// else if (map.exit.lst_uaxis->next)
	// {
	// 	ft_printf("Error\n");
	// 	debug_entity(map.exit.lst_uaxis->next, "Duplicate Exit");
	// 	ft_exit(0);
	// }
}

static void	ft_valid_unit(t_map *map)
{
	t_axis	i;

	i.y = -1;
	while (map->structure[++i.y])
	{
		i.x = -1;
		while (map->structure[i.y][++i.x])
			if (map->structure[i.y][i.x] == 'E')
				ft_lstadd_back(&map->exit.lst_uaxis, ft_lstnew_uaxis(i));
		else if (map->structure[i.y][i.x] == 'C')
			ft_lstadd_back(&map->collectible.lst_uaxis, ft_lstnew_uaxis(i));
		else if (map->structure[i.y][i.x] == 'P')
			ft_lstadd_back(&map->player.lst_uaxis, ft_lstnew_uaxis(i));
		else if (map->structure[i.y][i.x] == 'Z')
			ft_lstadd_back(&map->zombie.lst_uaxis, ft_lstnew_uaxis(i));
		else if (map->structure[i.y][i.x] != '0'
			&& map->structure[i.y][i.x] != '1')
			ft_error_map(*map, "Invalid unit", &i);
	}
}

static int	ft_map_intact_topdown(char *str, t_axis *i)
{
	i->x = 0;
	while (str[i->x] == '1')
		i->x++;
	return (!str[i->x]);
}

static void	ft_map_border(t_map map)
{
	t_axis	i;

	i.y = 0;
	if (!ft_map_intact_topdown(map.structure[i.y], &i))
		ft_error_map(map, "Incomplete Border", &i);
	i.x--;
	while (map.structure[++i.y + 1])
		if (map.structure[i.y][0] != '1')
			ft_error_map(map, "Incomplete Border", &(t_axis){0, i.y});
	else if (map.structure[i.y][i.x] != '1')
		ft_error_map(map, "Incomplete Border", &i);
	if (!ft_map_intact_topdown(map.structure[i.y], &i))
		ft_error_map(map, "Incomplete Border", &i);
}

t_map	ft_map_evaluate(t_map map)
{
	size_t	len;
	
	map.size.y = 0;
	map.size.x = ft_strlen(map.structure[map.size.y]);
	while (map.structure[++map.size.y])
	{
		len = ft_strlen(map.structure[map.size.y]);
		if (!len)
			ft_error_map(map, "Excessive Newline", &(t_axis){0, map.size.y});
		else if (len != map.size.x)
			ft_error_map(map, "Unalign Border", &map.size);
	}
	ft_map_border(map);
	ft_valid_unit(&map);
	if (map.size.y < 3 || map.size.x < 3
		|| (map.size.y == 3 && map.size.x == 3))
		ft_error_map(map, "Map too small", 0);
	ft_map_unit(map);
	ft_validpath(map);
	return (map);
}
