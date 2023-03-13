/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:46 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:57:48 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_clock(t_game *g)
{
	if (!(++g->frame % ((FPS / UPS) * 16)))
		ft_pathfind(g, g->map.zombie.lst_uaxis, g->map.player.lst_uaxis);
	if (!(g->frame % (FPS / UPS)))
		ft_update(g);
	return (0);
}

int	ft_digit_count(size_t nbr)
{
	int	digit;

	digit = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

void	ft_memprint(void *ptr, size_t bytes, int data_size)
{
	int		pad;
	uint8_t	*ucptr;
	size_t	i_b;
	size_t	i;

	if (data_size <= 0)
		return ;
	ucptr = ptr;
	i_b = 1;
	pad = ft_digit_count(bytes);
	while (bytes)
	{
		ft_printf("(%*d)bytes: ", pad, i_b++);
		i = data_size;
		while (i-- && bytes)
		{
			ft_printf(" [%3d]", *ucptr++);
			bytes--;
		}
		ft_printf("\n");
	}
}

void	so_long(char *file_map)
{
	t_game	g;

	g = topdown(file_map);
	
	// t_data	data_collect = ft_data_address(g.map.collectible.lst_img->content);
	// ft_memprint(data_collect.address, data_collect.size, sizeof(int));
	mlx_loop_hook(g.mlx, ft_clock, &g);
	mlx_hook(g.win, 2, 1L<<0, ft_input, &g);
	mlx_hook(g.win, EXIT_EVENT, 0, ft_close, &g);
	mlx_loop(g.mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_printf("Error\nMissing map\n"));
	else if (argc > 2)
		return (ft_printf("Error\nToo many map\n"));
	so_long(argv[1]);
}
