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
# include <stdio.h>

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
	int		l;
	int		k;
	int		memory;
	char	*enemy_path;
	char	*exit_path;
	char	*move;
	int		update;
}	t_solong;

char	**check_map(int fd, t_solong *win);
int		player_hook(int keycode, t_solong *win);
int		scean_update(t_solong *win);
void	ft_exit(void);
char	*ft_strjoin(char *str, char *buf);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t i, size_t s);
char	*ft_itoa(int r);
int		check_collisions(t_solong *win, int move);
int		ft_animations(t_solong *win, int event);
void	ft_putstr(char *c);

#endif