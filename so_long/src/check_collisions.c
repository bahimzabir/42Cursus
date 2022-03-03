/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:32:27 by azabir            #+#    #+#             */
/*   Updated: 2022/02/28 00:32:29 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	exit_status(int i, int j, t_solong *win)
{
	int		count;
	char	**map;

	map = win->map;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				count += 1;
			j += 1;
		}
		i += 1;
	}
	if (count == 0)
	{
		win->exit_path = "./assets/exit/2.xpm";
		win->player_path = "./assets/player/3.xpm";
	}
	return (count);
}

int	exit_status2(int i, int j, t_solong *win)
{
	int		count;
	char	**map;

	map = win->map;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count += 1;
			j += 1;
		}
		i += 1;
	}
	if (count == 0)
	{
		win->enemy_path = "./assets/enemy/2.xpm";
		win->player_path = "./assets/player/2.xpm";
	}
	return (count);
}

int	check_collisions(t_solong *win)
{
	if (win->map[win->l][win->k] == 'C')
		win->map[win->l][win->k] = '0';
	else if (exit_status2(0, 0, win) && win->map[win->l][win->k] == 'N')
		ft_exit("\nGAME OVER!!\n You hit an enemy\n");
	else if (!exit_status(0, 0, win) && win->map[win->l][win->k] == 'E')
		ft_exit("\nYOU WIN!!\n CONGRATS :-D\n");
	return (1);
}
