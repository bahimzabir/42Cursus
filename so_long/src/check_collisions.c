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

int	check_collisions(t_solong *win, int move)
{
	if (win->map[win->l][win->k] == 'C')
	{
		win->map[win->l][win->k] = '0';
		scean_update (win, win->map, move);
	}
	else if (win->map[win->l][win->k] == 'N')
	{
		//ft_animations(win, 1);
		ft_exit();
	}
	return (1);
}