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

#include "include/solong.h"

int	main(void)
{
	t_solong	window;
	//t_solong	player;
	char		**map;
	int			fd;

	fd = open("./assets/map/map.ber", O_RDONLY);
		map = check_map(fd, &window.x, &window.y);
	/*window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.x, window.y, "So_Long");
	mlx_key_hook(window.mlx, player_hook, &player);
	player.update = scean_update(&player, &map);
	if (player.update == -1)
		ft_exit();*/
}
