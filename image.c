/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 11:45:50 by pmotala           #+#    #+#             */
/*   Updated: 2018/07/30 15:01:15 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIDTH - 1 || y >= HEIGHT - 1)
		return ;
	*(int *)(image->ptr + ((x + y * WIDTH) * image->bpp)) = color;
}

void	clear_image(t_mlx *mlx)
{
	ft_bzero(mlx->image->ptr, WIDTH * HEIGHT * mlx->image->bpp);
}

t_image	*del_image(t_image *image, t_mlx *mlx)
{
	if (image != NULL)
	{
		if (image->image != NULL)
			mlx_destroy_image(mlx->mlx, image->image);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

t_image	*init_img(t_mlx *mlx)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		return (del_image(img, mlx));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp,
		&img->sizel, &img->endian);
	img->bpp /= 8;
	return (img);
}
