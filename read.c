/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:02:40 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:19:38 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col_row(t_mlx *mlx, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (mlx->info.rows == 0)
		mlx->info.cols = x;
	else
	{
		if (x != mlx->info.cols)
			return (-1);
	}
	free(line);
	free(tab);
	mlx->info.rows++;
	return (0);
}

int			ft_alloc_tab(t_mlx *mlx)
{
	char	*line;
	int		ret;

	line = NULL;
	mlx->info.rows = 0;
	mlx->info.cols = 0;
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		if (ft_col_row(mlx, line) == -1)
			return (-1);
	}
	mlx->map = ft_memalloc(sizeof(t_vector*) * mlx->info.rows);
	close(mlx->fd);
	mlx->fd = open(mlx->name, O_RDONLY);
	return (0);
}

int			ft_read(t_mlx *mlx)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	if (ft_alloc_tab(mlx) == -1)
		return (-1);
	while ((xytab[2] = get_next_line(mlx->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		mlx->map[xytab[1]] = ft_memalloc(sizeof(t_vector) * mlx->info.cols);
		while (tab[xytab[0]] != NULL)
		{
			mlx->map[xytab[1]][xytab[0]].x = xytab[0];
			mlx->map[xytab[1]][xytab[0]].y = xytab[1];
			mlx->map[xytab[1]][xytab[0]].z = ft_atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		free(line);
		xytab[1]++;
	}
	return ((xytab[2] == -1) ? -1 : 0);
}
