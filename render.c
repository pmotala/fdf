/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:49:13 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:20:44 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx *mlx, t_vector *p1, t_vector *p2)
{
	int i[2];
	int e2;
	int color;

	mlx->info.bres = bres_const(p1, p2);
	i[0] = p1->d2x;
	i[1] = p1->d2y;
	while (1)
	{
		color = choose_color(get_highest(p1, p2, mlx));
		set_pixel(mlx->image, create_x(mlx, i[0]), create_y(mlx, i[1]), color);
		if (i[0] == p2->d2x && i[1] == p2->d2y)
			break ;
		if ((e2 = mlx->info.bres->err) > -(mlx->info.bres->dx))
		{
			mlx->info.bres->err -= mlx->info.bres->dy;
			i[0] += mlx->info.bres->sx;
		}
		if (e2 < mlx->info.bres->dy)
		{
			mlx->info.bres->err += mlx->info.bres->dx;
			i[1] += mlx->info.bres->sy;
		}
	}
	free(mlx->info.bres);
}

void	ft_render(t_mlx *mlx)
{
	int x;
	int	y;

	y = 0;
	while (y < mlx->info.rows)
	{
		x = 0;
		while (x < mlx->info.cols)
		{
			if (x < mlx->info.cols - 1)
				draw_line(mlx, &(mlx->map[y][x]), &(mlx->map[y][x + 1]));
			if (y < mlx->info.rows - 1)
				draw_line(mlx, &(mlx->map[y][x]), &(mlx->map[y + 1][x]));
			x++;
		}
		y++;
	}
}
