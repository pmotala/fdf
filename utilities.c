/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:40:36 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:17:43 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cnv_dbl_int(double num)
{
	int		i;
	double	j;

	i = (int)num;
	j = num - (double)i;
	if (j <= 0.5)
		return (i);
	else
		return (i + 1);
}

int		choose_color(int p1)
{
	if (p1 == 0)
		return (GREEN);
	else if (p1 > 0 && p1 < 5)
		return (MAROON);
	else if (p1 >= 5 && p1 < 10)
		return (RED);
	else if (p1 >= 10 && p1 < 14)
		return (ORANGE);
	else if (p1 >= 14 && p1 <= 20)
		return (YELLOW);
	else if (p1 > 20)
		return (WHITE);
	else if (p1 < 0 && p1 > -10)
		return (LIME);
	else if (p1 <= -10 && p1 > -14)
		return (AQUA);
	else if (p1 <= -14 && p1 >= -20)
		return (BLUE);
	else if (p1 < -20)
		return (NAVY);
	return (SILVER);
}

int		get_highest(t_vector *p1, t_vector *p2, t_mlx *mlx)
{
	if (p1->z > p2->z)
		return (p1->z * mlx->depth);
	return (p2->z * mlx->depth);
}

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
