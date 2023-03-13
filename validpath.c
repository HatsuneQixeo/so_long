/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:59:31 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:59:32 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static t_list	*ft_search(char **structure, char c)
{
	t_axis	i;
	char	*c_str;
	t_list	*c_axis;

	i.y = -1;
	c_axis = 0;
	while (structure[++i.y])
	{
		c_str = ft_strchr(structure[i.y], c);
		while (c_str)
		{
			i.x = c_str - structure[i.y];
			ft_lstadd_back(&c_axis, ft_lstnew_uaxis(i));
			c_str = ft_strchr(&structure[i.y][++i.x], c);
		}
	}
	return (c_axis);
}

static void	ft_leftover(char **validpath, char c)
{
	t_list	*leftover;

	leftover = ft_search(validpath, c);
	if (!leftover)
		return ;
	debug_structure(validpath);
	ft_printf("Error\nUnreachable Unit: %c\n", c);
	debug_entity(leftover, "Leftover");
	ft_lstclear(&leftover, free);
	ft_clear_strlist(validpath);
	ft_exit(0);
}

static void	ft_floodfill_stop(char **structure, t_axis i, char stop)
{
	if (structure[i.y][i.x] == stop || structure[i.y][i.x] == 'F')
		return ;
	structure[i.y][i.x] = 'F';
	ft_floodfill_stop(structure, (t_axis){i.x, i.y + 1}, stop);
	ft_floodfill_stop(structure, (t_axis){i.x + 1, i.y}, stop);
	ft_floodfill_stop(structure, (t_axis){i.x, i.y - 1}, stop);
	ft_floodfill_stop(structure, (t_axis){i.x - 1, i.y}, stop);
}

void	ft_validpath(t_map map)
{
	char	**validpath;
	t_list	*player;

	validpath = ft_strlistdup(map.structure);
	player = map.player.lst_uaxis;
	while (player)
	{
		ft_floodfill_stop(validpath, ft_getaxis(player->content), '1');
		player = player->next;
	}
	ft_leftover(validpath, 'C');
	ft_leftover(validpath, 'E');
	ft_clear_strlist(validpath);
}
