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

void	put_update(t_solong *win, char **map, int l, int k)
{
	while (map[k / 50][l / 50])
	{
		if (map[k / 50][l / 50] == 'E')
		{
			ft_file_to_image(win, win->exit_path);
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
		}
		else if (map[k / 50][l / 50] == 'P')
		{
			ft_file_to_image(win, win->player_path);
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
		}
		else if (map[k / 50][l / 50] == 'N')
		{
			ft_file_to_image(win, win->enemy_path);
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
		}
		else if (map[k / 50][l / 50] == '0')
		{
			ft_file_to_image(win, "./assets/background/2");
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
		}
			l += 50;
	}
}

void	put_counter(t_solong *win)
{
	ft_putstr(win->move);
	ft_file_to_image(win, "./assets/wall/wall.xpm");
	mlx_put_image_to_window(win->mlx, win->win, win->img, 50, 0);
	mlx_string_put(win->mlx, win->win, 50, 11, 0x000000, win->move);
}

int	scean_update(t_solong *win)
{
	int				l;
	int				k;
	char			**map;
	static int		move = -1;

	if (move == win->update)
		return (0);
	map = win->map;
	move = win->update;
	win->move = ft_itoa(move);
	k = 0;
	l = 0;
	while (map[k / 50])
	{
		l = 0;
		put_update(win, map, l, k);
		k += 50;
	}
	put_counter(win);
	free (win->move);
	return (1);
}
