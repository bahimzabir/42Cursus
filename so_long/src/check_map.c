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

int	check1(char **map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (map[j][i])
	{
		if (j == 0 && map[j][i] != '1')
			ft_exit();
		i++;
	}
	while (map[j])
	{	
		if (map[j][0] != '1' || map[j][i - 1] != '1' || ft_strlen(map[j]) != ft_strlen(map[0]))
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

int	check2 (char **map)
{
	t_solong check;
	
	check.x = 0;
	check.y = 0;

	while(map[check.x])
	{
		check.y = 0;
		while (map[check.x][check.y])
			{
				if (map[check.x][check.y] == 'C')
					check.i = 1;
				else if (map[check.x][check.y] == 'P')
					check.j = 1;
				else if (map[check.x][check.y] == 'E')
					check.k = 1;
				else  if (map[check.x][check.y] != '1' && map[check.x][check.y] != '0' && map[check.x][check.y] != 'N')
					ft_exit();
				check.y += 1;
			}
		check.x += 1;
	}
	if (check.i + check.j + check.k != 3)
		ft_exit();
	return(check.x);
}

char	**check_map(int fd, int *x, int *y)
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
			break;
		if (i == -1)
			ft_exit();
		map = ft_strjoin(map, c);
	}
	printf("\n%s\n", map);
	map2d = ft_split(map, '\n');
	*x = check1(map2d) * 50;
	*y = check2(map2d) * 50;
	printf("\n(%d, %d)\n", *x, *y);
	return (map2d);
}
