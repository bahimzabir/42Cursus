/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:43:53 by azabir            #+#    #+#             */
/*   Updated: 2022/02/23 11:43:55 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	put_player(t_solong *win)
{
	if (win->map[win->l][win->k] != 'E')
		win->map[win->l][win->k] = 'P';
}

void	put_ground(t_solong *win)
{
	if (win->map[win->l][win->k] != 'E')
		win->map[win->l][win->k] = '0';
}

int	player_hook(int keycode, t_solong *win)
{
	static int	move = 1;

	put_ground(win);
	win->update = move;
	if (keycode == 0 && win->map[win->l][win->k - 1] != '1')
		win->k -= 1;
	else if (keycode == 13 && win->map[win->l - 1][win->k] != '1')
		win->l -= 1;
	else if (keycode == 2 && win->map[win->l][win->k + 1] != '1')
		win->k += 1;
	else if (keycode == 1 && win->map[win->l + 1][win->k] != '1')
		win->l += 1;
	else if (keycode == 53)
		ft_exit("\nGAME STOPED: You Closed the GAME\n");
	else
	{	
		if (win->map[win->l][win->k] != 'E')
			win->map[win->l][win->k] = 'P';
		win->update = move - 1;
		return (1);
	}
	check_collisions(win);
	put_player(win);
	move ++;
	return (0);
}
