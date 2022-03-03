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
	char	*map1;
	int		x;
	int		y;
	int		i;
	int		j;
	int		l;
	int		k;
	int		memory;
	char	*enemy_path;
	char	*exit_path;
	char	*player_path;
	char	*move;
	int		update;
}	t_solong;

void	check_map(int fd, t_solong *win);
int		player_hook(int keycode, t_solong *win);
int		scean_update(t_solong *win);
void	ft_exit(char *msg);
char	*ft_strjoin(char *str, char *buf);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t i, size_t s);
char	*ft_itoa(int r);
int		check_collisions(t_solong *win);
void	ft_putstr(char *c);
void	ft_file_to_image(t_solong *win, char *path);
void	put_path(t_solong *win);
int		check_file(char *path);
void	check_newline(t_solong *win);

#endif