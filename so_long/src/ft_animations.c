/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:50:06 by azabir            #+#    #+#             */
/*   Updated: 2022/02/28 01:50:08 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_animations(t_solong *win,int event)
{
	int i;
	int	j;

	/*win->enemy_path[0] = "./assets/enemy/1.xpm";
	win->enemy_path[1] = "./assets/enemy/2.xpm";
	win->enemy_path[2] = "./assets/enemy/3.xpm";*/
	i = 0;
	j = 1;
	if (event == 1)
	{
		while (i <= 100)
		{
			j = 1;
			while (j <= 4)
			{
				win->img = mlx_xpm_file_to_image(win->mlx, ft_itoa(j), &win->i, &win->j);
				mlx_put_image_to_window(win->mlx, win->win, win->img, win->l * 50, win->k * 50);
				j++;
			}
			i++;
		}
	}
	return (1);
}
