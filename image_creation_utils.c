/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:09:40 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/27 20:09:49 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl_image_factory.h"

//Return colour value with given rgba
unsigned int	ft_get_colour(unsigned char r, unsigned char g,
		unsigned char b, unsigned char a)
{
	return ((r * 0x010000) + (g * 0x0100) + b + (a * 0x01000000));
}

t_data	ft_data_address(t_image *image)
{
	t_data	data;

	data.address = mlx_get_data_addr
		(image->mlx, &data.bits_per_pixel, &data.size_line, &data.endian);
	data.size = data.size_line * image->height;
	return (data);
}

//Draw the src image into dst in given coordinate inside dst
void	ft_mlx_imgcpy(t_data dst, t_data src, t_axis axis)
{
	size_t	i;
	size_t	i_src;

	i = (axis.y * dst.size_line * PIXEL) + (axis.x * PIXEL * sizeof(int));
	i_src = 0;
	while (src.size - i_src && i < dst.size)
	{
		ft_memcpy(&dst.address[i], &src.address[i_src], src.size_line);
		i += dst.size_line;
		i_src += src.size_line;
	}
}

//Fill the src image into dst from i to end
//Note: this can only draw rectangle or square
void	ft_mlx_imgfill(t_data dst, t_data src, t_axis i, t_axis end)
{
	size_t	x;

	i.y--;
	x = --i.x;
	while (++i.y < end.y)
	{
		i.x = x;
		while (++i.x < end.x)
			ft_mlx_imgcpy(dst, src, i);
	}
}

//Straight out extract the image from an xpm file
t_image	*ft_image_xpm(void *mlx, char *file)
{
	t_image	*img;
	int		fd;

	if (!ft_file_format(file, ".xpm"))
		return (0);
	fd = ft_file_open(file);
	if (fd < 0)
		return (0);
	close(fd);
	img = malloc(sizeof(t_image));
	img->mlx = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
	return (img);
}

//Find the given colour inside given image data within given size
//and apply the given transparency of the colour in given image data
//0 is opaque, 255 is fully transparent
//Note: This function take transparency into comparison
//Remain unused for this project
// void	ft_transparent(t_data data, size_t size,
// 			unsigned int colour, unsigned char transparency)
// {
// 	unsigned int	*ptr;

// 	ptr = (unsigned int *)data.address;
// 	size /= 4;
// 	while (size--)
// 	{
// 		if (*ptr == colour)
// 			*ptr = (*ptr % VALUE_T) + (VALUE_T * transparency);
// 		ptr++;
// 	}
// }

void	ft_img_transparentize(t_data data, uint8_t transparency)
{
	uint32_t	*ptr;
	size_t		size;

	ptr = (uint32_t *)data.address;
	size = data.size / 4;
	while (size--)
	{
		*ptr = (*ptr % VALUE_T) + (VALUE_T * transparency);
		ptr++;
	}
}
