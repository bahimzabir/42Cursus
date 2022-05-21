/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:42:13 by azabir            #+#    #+#             */
/*   Updated: 2022/05/21 18:42:15 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	data_init(t_philo *data)
{
	struct timeval	time;

	data->pids = malloc(sizeof(int) * data->nof);
	gettimeofday(&time, NULL);
	data->inittime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	data->philos_done = 0;
	data->all_alive = 1;
}
