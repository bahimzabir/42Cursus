/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scean_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:53:22 by azabir            #+#    #+#             */
/*   Updated: 2022/02/23 18:53:23 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	scean_update(t_solong *win, char **map, int move)
{
	int k = 0;
	int l = 0;
	while (map[k / 50])
	{
		l = 0;
		while (map[k / 50][l / 50])
		{
			if (map[k / 50][l / 50] == '1')
				win->img = mlx_xpm_file_to_image(win->mlx, "./assets/wall/wall.xpm", &win->i, &win->j);
			else if (map[k / 50][l / 50] == 'C')
				win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/col/1.xpm", &win->i, &win->j);
			else if (map[k / 50][l / 50] == 'E')
				win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/exit/2.xpm", &win->i, &win->j);
			else if (map[k / 50][l / 50] == 'N')
				win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/enemy/2.xpm", &win->i, &win->j);
			else if (map[k / 50][l / 50] == 'P')
				win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/player/1.xpm", &win->i, &win->j);
			else
			win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/background/1.xpm", &win->i, &win->j);
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
			l += 50;
		}
		k += 50;
	}
	mlx_string_put(win->mlx, win->win, 50, 11, 0x000000, ft_itoa(move));
	return(1);
}
