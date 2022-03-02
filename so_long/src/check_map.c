/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:33:02 by azabir            #+#    #+#             */
/*   Updated: 2022/02/22 23:33:04 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	check1(char **map, t_solong *win, int i, int j)
{
	while (map[j][i])
	{
		if (j == 0 && map[j][i] != '1')
			ft_exit();
		i++;
	}
	while (map[j])
	{	
		if (map[j][0] != '1' || map[j][i - 1] != '1' || ft_strlen(map[j])
				!= ft_strlen(map[0]))
			ft_exit();
		j++;
	}
	i = 0;
	while (map[j - 1][i])
	{
		if (map [j - 1][i] != '1')
			ft_exit();
		i++;
	}
	return (i);
}

int	check3(t_solong *check, char **map, int x)
{
	while (map[x])
	{
		check->y = 0;
		while (map[x][check->y])
		{
			if (map[x][check->y] == 'C')
				check->i = 1;
			else if (map[x][check->y] == 'E')
				check->k = 1;
			else if (map[x][check->y] != '1' && map[x][check->y]
				!= '0' && map[x][check->y] != 'N'
				&& map[x][check->y] != 'P')
				ft_exit();
			check->y += 1;
		}
		x += 1;
	}
	return (check->i + check->k);
}

int	check2(char **map, t_solong *win, int x, int j)
{
	t_solong	check;

	while (map[x])
	{
		check.y = 0;
		while (map[x][check.y])
		{
			if (map[x][check.y] == 'P')
			{
				j += 1;
				win->l = x;
				win->k = check.y;
			}
			check.y += 1;
		}
		x += 1;
	}
	if (check3(&check, map, 0) + j != 3)
		ft_exit();
	return (x);
}

char	**check_map(int fd, t_solong *win)
{
	int		i;
	char	*c;
	char	*map;
	char	**map2d;

	c = malloc(sizeof(char) + 1);
	c[1] = 0;
	map = malloc(sizeof(char) + 1);
	i = 1;
	while (i != 0)
	{
		i = read(fd, c, 1);
		if (i == 0)
			break ;
		if (i == -1)
			ft_exit();
		map = ft_strjoin(map, c);
	}
	map2d = ft_split(map, '\n');
	win->x = check1(map2d, win, 0, 0) * 50;
	win->y = check2(map2d, win, 0, 0) * 50;
	return (map2d);
}
