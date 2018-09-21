/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:15:36 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:15:57 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		create_x(t_mlx *win, int x)
{
	return (x + win->move_lr);
}

int		create_y(t_mlx *win, int y)
{
	return (y + win->move_ud);
}

t_bres	*bres_const(t_vector *p1, t_vector *p2)
{
	t_bres	*bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->dx = ft_abs(p2->d2x - p1->d2x);
	bres->sx = p1->d2x < p2->d2x ? 1 : -1;
	bres->dy = ft_abs(p2->d2y - p1->d2y);
	bres->sy = p1->d2y < p2->d2y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
	return (bres);
}
