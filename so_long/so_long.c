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

	i = 0;
	while (i <= window->x)
	{	
		j = 0;
		while (j <= window->y)
		{
			ft_file_to_image(window, "./assets/background/2");
			mlx_put_image_to_window(window->mlx, window->win,
				window->img, i, j);
			j += 50;
		}
		i += 50;
	}
	return (1);
}

void	put_image(t_solong *win, char **map, int l, int k)
{
	while (map[k / 50][l / 50])
	{
		if (map[k / 50][l / 50] == '1')
			ft_file_to_image(win, "./assets/wall/wall.xpm");
		else if (map[k / 50][l / 50] == 'C')
			ft_file_to_image(win, "./assets/col/1.xpm");
		else if (map[k / 50][l / 50] == 'E')
			ft_file_to_image(win, win->exit_path);
		else if (map[k / 50][l / 50] == 'N')
			ft_file_to_image(win, win->enemy_path);
		else if (map[k / 50][l / 50] == 'P')
			ft_file_to_image(win, win->player_path);
		else
			ft_file_to_image(win, "./assets/background/2");
		mlx_put_image_to_window(win->mlx, win->win, win->img, l, k);
			l += 50;
	}
}

int	ft_exite(char *msg)
{
	ft_exit(msg);
	return (0);
}

int	main(void)
{
	t_solong	window;
	int			fd;
	int			k;

	window.update = 0;
	k = 0;
	window.exit_path = "./assets/exit/1.xpm";
	window.enemy_path = "./assets/enemy/1.xpm";
	window.player_path = "./assets/player/1.xpm";
	fd = open("./assets/map/map.ber", O_RDONLY);
	if (fd <= 0)
		ft_exit("Error: can't open the map file!\n");
	check_map(fd, &window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.x, window.y, "So_Long");
	put_bg (&window);
	while (window.map[k / 50])
	{
		put_image (&window, window.map, 0, k);
		k += 50;
	}
	mlx_key_hook(window.win, player_hook, &window);
	mlx_loop_hook (window.mlx, scean_update, &window);
	mlx_hook(window.win, 17, 0, ft_exite, "GAME STOPED: You Closed the GAME");
	mlx_loop(window.mlx);
}
