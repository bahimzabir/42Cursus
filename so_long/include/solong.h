/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:21:15 by azabir            #+#    #+#             */
/*   Updated: 2022/02/23 11:21:18 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
	int		update;
}	t_solong;

char	**check_map(int fd, int *x, int *y);
void	player_hook(int keycode, t_solong *player);
int		scean_update(t_solong *player, char	**map);
void	ft_exit();
char	*ft_strjoin(char *str, char *buf);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t i, size_t s);

#endif