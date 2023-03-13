/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_factory.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:46:09 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/25 02:46:10 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_IMAGE_FACTORY_H
# define SL_IMAGE_FACTORY_H

# include "libft.h"
# include <mlx.h>

# define PIXEL		48
# define BAR_HEIGHT	1
# define VALUE_T	0x01000000

typedef struct image
{
	void	*mlx;
	int		width;
	int		height;
}			t_image;

typedef struct data
{
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	size_t	size;
}			t_data;

typedef struct axis
{
	size_t	x;
	size_t	y;
}				t_axis;

typedef struct axis_range
{
	unsigned int	colour;
	t_axis			start;
	t_axis			end;
}			t_range;

unsigned int	ft_get_colour(unsigned char r, unsigned char g,
					unsigned char b, unsigned char a);
t_data			ft_data_address(t_image *image);
void			ft_intset(unsigned int *ptr, unsigned int set, size_t len);
void			ft_mlx_imgcpy(t_data dst, t_data src, t_axis axis);
void			ft_mlx_colourfill(t_data data, unsigned int colour,
					t_axis start, t_axis end);
void			ft_mlx_imgfill(t_data dst, t_data src, t_axis i, t_axis end);

t_image			*ft_image_xpm(void *mlx, char *file);
t_image			*ft_mlx_create_ptr(void *mlx, unsigned int colour);
#endif
