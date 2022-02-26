/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:32:38 by azabir            #+#    #+#             */
/*   Updated: 2022/02/22 23:32:41 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/solong.h"

int	put_bg(t_solong *window)
{
	int			i;
	int			j;
	static int	k = 3;
	char	map_path[2][30] = {"./assets/background/1.xpm","./assets/background/2.xpm"};

	i = 0;
	while (i <= window->x)
	{	
		j = 0;
		while (j <= window->y)
		{
			window->img	= mlx_xpm_file_to_image(window->mlx, map_path[1], &window->i, &window->j);
			mlx_put_image_to_window(window->mlx, window->win, window->img, i, j);
			j += 50;
		}
		i += 50;
	}
	k += 1;
	printf("%d\n", k);
	return(1);
}

int put_map(t_solong *win, char **map)
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
			else
				win->img = mlx_xpm_file_to_image(win->mlx,  "./assets/background/1.xpm", &win->i, &win->j);
			mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
			write(1, &map[k / 50][l / 50], 1);
			l += 50;
		}
		k += 50;
	}
	return(1);
}

int	main(void)
{
	t_solong	window;
	t_solong	player;
	int			fd;

	fd = open("./assets/map/map.ber", O_RDONLY);
		player.map = check_map(fd, &window.x, &window.y);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.x, window.y, "So_Long");
	//mlx_key_hook(window.mlx, player_hook, &window);
	//player.update = put_bg(window);
	put_bg (&window);
	//put_map (&window, player.map);
	mlx_loop_hook(window.mlx, scean_update, &window);
	/*if (player.update == -1)
		ft_exit();*/
	mlx_loop(window.mlx);
}
