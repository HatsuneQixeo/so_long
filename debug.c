/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:09 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 21:57:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	debug_data(t_data data, char *name)
{
	ft_printf("%s.address: %p\n", data.address);
	ft_show_rgba(data.address, data.size);
	ft_printf("%s.size_line: %d\n", name, data.size_line);
	ft_printf("%s.endian: %d\n", name, data.endian);
	ft_printf("%s.size: %d\n", name, data.size);
}

void	debug_structure(char **structure)
{
	if (!structure)
		ft_printf("(null structure)\n");
	else if (!*structure)
		ft_printf("Empty structure\n");
	else
		while (*structure)
			ft_printf("%s\n", *structure++);
}

void	debug_axis(t_axis axis, char *name, int nbr)
{
	ft_printf("%s(%d)", name, nbr);
	ft_printf(": x = %d, y = %d\n", axis.x, axis.y);
}

void	debug_entity(t_list *entity, char *name)
{
	int	serialnum;

	serialnum = 0;
	ft_shout(name);
	if (!entity)
		ft_printf("%s not found\n", name);
	while (entity)
	{
		debug_axis(ft_getaxis(entity->content), name, ++serialnum);
		entity = entity->next;
	}
}
