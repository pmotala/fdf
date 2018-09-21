/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:14:47 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:15:26 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(int key, t_mlx *mlx)
{
	if (key == 12 && mlx->scale <= 160)
	{
		mlx->scale += 4;
		erase(mlx);
	}
	else if (key == 0 && mlx->scale > 8)
	{
		mlx->scale -= 4;
		erase(mlx);
	}
	if (key == 13 && mlx->scale > 8)
	{
		mlx->scale /= 2;
		erase(mlx);
	}
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	ft_xy_trans(int key, t_mlx *mlx)
{
	if ((key >= 123 && key <= 126) || key == 15)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		if (key == 123)
			mlx->move_lr -= 10;
		if (key == 126)
			mlx->move_ud -= 10;
		if (key == 124)
			mlx->move_lr += 10;
		if (key == 125)
			mlx->move_ud += 10;
		erase(mlx);
	}
}

void	ft_depth(int key, t_mlx *mlx)
{
	if (key == 6 && mlx->depth < mlx->depth_max)
	{
		mlx->depth += 0.1f;
		erase(mlx);
	}
	if (key == 7 && mlx->depth > mlx->depth_min)
	{
		mlx->depth -= 0.1f;
		erase(mlx);
	}
}
