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
			window->img = mlx_xpm_file_to_image(window->mlx,
					"./assets/background/2", &window->i, &window->j);
			mlx_put_image_to_window(window->mlx, window->win,
				window->img, i, j);
			j += 50;
		}
		i += 50;
	}
	return (1);
}

int	main(void)
{
	t_solong	window;
	t_solong	player;
	int			fd;

	window.update = 0;
	window.exit_path = "./assets/exit/1.xpm";
	fd = open("./assets/map/map.ber", O_RDONLY);
		window.map = check_map(fd, &window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.x, window.y, "So_Long");
	put_bg (&window);
	mlx_key_hook(window.win, player_hook, &window);
	mlx_loop_hook (window.mlx, scean_update, &window);
	mlx_loop(window.mlx);
}
