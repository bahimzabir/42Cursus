/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:48:40 by azabir            #+#    #+#             */
/*   Updated: 2022/04/18 20:48:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct s_thread
{
	int				*id;
	pthread_t 		*philo;
} t_thread;

typedef struct s_philo
{
	int	nof;
	int	ttd;
	int	tte;
	int	tts;
	int	tme;
	pthread_mutex_t	*fork;
	t_thread philos;
}	t_philo;

void	ft_exit(void);
int		ft_atoi(char *s);
int 	*ft_forks(int	nof);
int 	*ft_philos(int	nof);
void	fill_data(t_philo *data, char	**arv);

#endif
