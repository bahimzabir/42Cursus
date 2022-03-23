/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:25:34 by azabir            #+#    #+#             */
/*   Updated: 2022/03/02 19:25:36 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_file_to_image(t_solong *win, char *path)
{
	win->img = mlx_xpm_file_to_image(win->mlx, path,
			&win->i, &win->j);
	if (win->img == NULL)
		ft_exit("ERROR\n invalid path\n");
}
