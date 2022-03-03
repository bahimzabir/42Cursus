/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:47:52 by azabir            #+#    #+#             */
/*   Updated: 2022/03/03 02:47:54 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	check_newline(t_solong *win)
{
	int	i;

	i = 0;
	if (win->map1[0] == '\0')
		ft_exit("\nERROR: Your map is empty\n");
	if (win->map1[0] == '\n')
		ft_exit("\nERROR: There is an empty line up your map\n");
	while (win->map1[i])
	{
		if (win->map1[i] == '\n')
		{
			if (win->map1 [i + 1] != '1' && win->map1 [i + 1] != '\0')
				ft_exit("\nERROR: There is an empty line in your map\n");
		}
		i++;
	}
	i--;
	if (win->map1[i] == '\n')
		ft_exit("\nERROR: There is an empty line down your map\n");
}
