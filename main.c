/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:48:37 by pmotala           #+#    #+#             */
/*   Updated: 2018/07/30 14:58:25 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_mlx *mlx)
{
	if (ft_read(mlx) == -1)
	{
		ft_putendl("ERROR DURING READ");
		return ;
	}
	init_mlx(mlx);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		mlx.name = av[1];
		mlx.fd = open(mlx.name, O_RDONLY);
		init(&mlx);
	}
	else
		ft_putendl("HOW TO USE: ./fdf file\nFILE IS MISSING");
	return (0);
}
