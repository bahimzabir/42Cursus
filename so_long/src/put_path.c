/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:12:03 by azabir            #+#    #+#             */
/*   Updated: 2022/03/03 02:12:05 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	put_path(t_solong *win)
{
	win->exit_path = "./assets/exit/1.xpm";
	win->enemy_path = "./assets/enemy/1.xpm";
	win->player_path = "./assets/player/1.xpm";
	win->update = 0;
}
