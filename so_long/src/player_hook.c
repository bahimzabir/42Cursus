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

int	player_hook(int keycode, t_solong *win)
{
	static int	move = 0;

	win->map[win->l][win->k] = '0';
	if(keycode == 0 && win->map[win->l][win->k - 1] != '1')
		win->k -= 1;
	else if(keycode == 13 && win->map[win->l - 1][win->k] != '1')
		win->l -= 1;
	else if(keycode == 2 && win->map[win->l][win->k + 1] != '1')
		win->k += 1;
	else if(keycode == 1 && win->map[win->l + 1][win->k] != '1')
		win->l += 1;
	else if(keycode == 53)
		ft_exit();
	else
		return (0);
	move ++;
	check_collisions(win, move);
	win->map[win->l][win->k] = 'P';
	scean_update (win, win->map, move);
	return (1);
}
