/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:02:46 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/16 22:02:47 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "sl_image_factory.h"

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2
# define EXIT_EVENT	17
# define FPS		8900
# define UPS		12

typedef struct uaxis
{
	t_axis	axis;
	t_axis	nextmove;
	int		vector;
}			t_uaxis;

typedef struct unit
{
	t_list	*lst_img;
	t_list	*lst_uaxis;
}			t_unit;

typedef struct map
{
	char	**structure;
	t_image	*map_img;
	t_image	*space;
	t_image	*wall;
	t_unit	player;
	t_unit	collectible;
	t_unit	exit;
	t_unit	zombie;
	t_image	*p_ptr;
	t_image	*z_ptr;
	t_image	*e_ptr;
	t_image	*ui;
	t_axis	size;
}			t_map;

typedef struct game
{
	void	*mlx;
	void	*win;
	t_map	map;
	size_t	frame;
	size_t	total_move;
}			t_game;

typedef t_axis (*t_get)(t_uaxis *);

t_image	*ft_map_image(t_game *g);

void	ft_update(t_game *g);
int		ft_clock(t_game *g);
int		ft_input(int key, t_game *g);

//validmap
t_map	ft_map_evaluate(t_map map);
void	ft_validpath(t_map map);

//exit
void	ft_exit(char *message);
void	ft_error_map(t_map map, char *reason, t_axis *i);
int		ft_close(t_game *g);

//init
t_game	topdown(char *file_map);

//debug
void	debug_data(t_data data, char *name);
void	debug_structure(char **structure);
void	debug_axis(t_axis axis, char *name, int nbr);
void	debug_entity(t_list *uaxis, char *name);

//debug_utils
void	ft_shout(const char *str);
void	ft_shownb(char *name, long long int nb);
void	ft_show_rgba(void *ptr, size_t size);

//pathfind
void	ft_pathfind(t_game *g, t_list *unit, t_list *target);

//UTILS
//math
int		ft_distance(int nb);
int		ft_direction(int x);
int		ft_mlx_invert(size_t axis, int size);
int		ft_mlx_centered(size_t axis, int size);
size_t	ft_distance_total(t_axis vector);

//axisfind
int		ft_axiscmp(t_axis axis1, t_axis axis2);
t_axis	ft_getaxis(t_uaxis *uaxis);
t_axis	ft_getnextmove(t_uaxis *uaxis);
t_list	*ft_uaxisaxis(t_list *lst, t_axis to_find, t_get get);
t_list	*ft_uaxisuaxis(t_list *lst, t_list *to_find,
			t_get get, t_get get_tofind);

//axis
t_axis	ft_vector(t_axis unit, t_axis target);
t_list	*ft_lstnew_uaxis(t_axis i);
void	ft_terminate(t_list **entity, t_axis position);

//render
void	ft_facing(t_uaxis *unit, size_t x);
void	ft_mlx_image(t_game *g, t_image *image, t_axis i, t_axis *offset);
void	ft_mlx_entityptr(t_game *g, t_image *image, t_list *lst_uaxis,
			t_get get);
void	ft_mlxnbr(t_game *g, size_t nb, t_axis *axis);
void	ft_mlx_entity(t_game *g, t_list *image, t_list *lst_uaxis,
			t_axis *offset);

#endif
