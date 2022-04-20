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

typedef struct s_philo
{
	int	nof;
	int	ttd;∏
	int	tte;
	int	tts;
	int	tme;
	int	*philos;
	int	*forks;
}	t_philo;

typedef struct s_action
{
	int		id;
	int		philo;
	int		time;
	struct s_action *next;
} t_action;

typedef struct s_fork
{
	int		busy;
	struct s_fork *next;
} t_fork;


void	ft_exit(void);
int		ft_atoi(char *s);

#endif
