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

int	check1(char **map, int i, int j)
{
	while (map[j][i])
	{
		if (j == 0 && map[j][i] != '1')
			ft_exit("ERROR\n up wall is not completed\n");
		i++;
	}
	while (map[j])
	{	
		if (map[j][0] != '1' || map[j][i - 1] != '1' || ft_strlen(map[j])
				!= ft_strlen(map[0]))
			ft_exit("ERROR\n side walls are not ligned\n");
		j++;
	}
	i = 0;
	while (map[j - 1][i])
	{
		if (map [j - 1][i] != '1')
			ft_exit("ERROR\n down wall is not completed\n");
		i++;
	}
	return (i);
}

int	check3(t_solong *check, char **map, int x)
{
	while (map[x])
	{
		check->y = 0;
		check->k = 0;
		while (map[x][check->y])
		{
			if (map[x][check->y] == 'C')
				check->i = 1;
			else if (map[x][check->y] == 'E')
				check->k = 1;
			else if (map[x][check->y] != '1' && map[x][check->y]
				!= '0' && map[x][check->y] != 'N'
				&& map[x][check->y] != 'P')
				ft_exit("ERROR\n indefined caracheter on the map\n");
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
		ft_exit("ERROR\n wrong number of characters allowed\n");
	return (x);
}

void	check_map(int fd, t_solong *win)
{
	char	*c;

	c = malloc(sizeof(char) + 1);
	c[1] = 0;
	win->map1 = malloc(sizeof(char) + 1);
	win->k = 1;
	while (win->k != 0)
	{
		win->k = read(fd, c, 1);
		if (win->k == 0)
			break ;
		if (win->k <= -1)
		{
			free(c);
			free (win->map1);
			ft_exit("ERROR\n can't read from the file\n");
		}
		win->map1 = ft_strjoin(win->map1, c);
	}
	free (c);
	check_newline(win);
	win->map = ft_split(win->map1, '\n');
	free(win->map1);
	win->x = check1(win->map, 0, 0) * 50;
	win->y = check2(win->map, win, 0, 0) * 50;
}
