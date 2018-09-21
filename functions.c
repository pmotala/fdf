/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:48:53 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:16:15 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_mlx *mlx)
{
	calcule_coord(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	return (0);
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_close();
	ft_depth(key, mlx);
	ft_scale(key, mlx);
	ft_xy_trans(key, mlx);
	return (0);
}

void	erase(t_mlx *mlx)
{
	clear_image(mlx);
	expose_hook(mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->info.check = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fdf");
	mlx->image = init_img(mlx);
	mlx->anglex = 0;
	mlx->angley = 0;
	mlx->scale = 4;
	mlx->depth = 1;
	mlx->move_lr = 1;
	mlx->move_ud = 1;
	mlx->depth_max = 2;
	mlx->depth_min = -2;
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_hook(mlx->win, MOUSE_DOWN, 0, &mouse_down, mlx);
	mlx_hook(mlx->win, MOUSE_MOVE, 0, &ft_rotate_map, mlx);
	mlx_loop(mlx->mlx);
}
