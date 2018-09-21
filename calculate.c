/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:13:14 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:14:38 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate(t_mlx *mlx, t_rot_point *rp)
{
	rp->px = cos(mlx->angley) * rp->act_px + sin(mlx->angley) * rp->act_pz;
	rp->pz = -sin(mlx->angley) * rp->act_px + cos(mlx->angley) * rp->act_pz;
	rp->py = cos(mlx->anglex) * rp->act_py - sin(mlx->anglex) * rp->pz;
}

void		ft_calculate(t_mlx *mlx, t_vector *pt)
{
	t_rot_point *rp;

	rp = (t_rot_point *)malloc(sizeof(t_rot_point));
	rp->act_px = (double)(pt->x - ((mlx->info.cols - 1) / 2));
	rp->act_py = (double)(pt->y - ((mlx->info.rows - 1) / 2));
	rp->act_pz = (double)(pt->z * mlx->depth);
	rotate(mlx, rp);
	rp->px *= mlx->scale;
	rp->py *= mlx->scale;
	pt->d2x = cnv_dbl_int(rp->px - rp->py + (WIDTH / 2));
	pt->d2y = cnv_dbl_int(rp->pz + rp->px + rp->py + (HEIGHT / 2));
	free(rp);
}

void		calcule_coord(t_mlx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->info.rows)
	{
		i = 0;
		while (i < mlx->info.cols)
		{
			ft_calculate(mlx, &(mlx->map[j][i]));
			i++;
		}
		j++;
	}
	ft_render(mlx);
}
