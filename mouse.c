/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:38:19 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:16:56 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse.button1 = 0;
	mlx->mouse.button1 = button;
	return (0);
}

int		ft_rotate_map(int x, int y, t_mlx *mlx)
{
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.button1 == 1)
	{
		mlx->anglex += (double)((mlx->mouse.lasty - mlx->mouse.y) / 200.0f);
		mlx->angley -= (double)((mlx->mouse.lastx - mlx->mouse.x) / 200.0f);
		erase(mlx);
	}
	return (0);
}
