/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:49:25 by azabir            #+#    #+#             */
/*   Updated: 2022/05/21 18:49:27 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	kill_all(t_philo *data)
{
	int	index;

	index = 0;
	while(index < data->nof)
	{
		kill(data->pids[index], SIGINT);
		index++;
	}
}
