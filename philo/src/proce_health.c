/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proce_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:15:12 by azabir            #+#    #+#             */
/*   Updated: 2022/05/21 16:15:14 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*proce_health(void	*arg)
{
	t_philo	*th;
	int		id;

	th = (t_philo *)arg;
	id = (th->id);
	while (1)
	{
		if(time_now() - th->last_meal >= th->ttd)
		{
			sem_wait(th->print_pause);
			printf("\033[0;31m%ld  philo %d died\033[0m\n", timestamp(th),id);
			exit(1);
		}
	}
	return(NULL);
}
