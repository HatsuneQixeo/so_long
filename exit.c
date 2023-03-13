/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:15 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:57:16 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_exit(char *message)
{
	if (message)
		ft_printf("%s\n", message);
	system("leaks -q so_long");
	exit(0);
}

void	ft_error_map(t_map map, char *reason, t_axis *i)
{
	debug_structure(map.structure);
	ft_printf("Error\n%s", reason);
	if (i)
		ft_printf(": %c (%s) y:%d x:%d",
			map.structure[i->y][i->x], map.structure[i->y], i->y, i->x);
	ft_printf("\n");
	ft_exit(0);
}

int	ft_close(t_game *g)
{
	if (!g->map.player.lst_uaxis)
		ft_exit("Game Over\n");
	ft_exit("Game Closed\n");
	return (831);
}
