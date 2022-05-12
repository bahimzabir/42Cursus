/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:50:28 by azabir            #+#    #+#             */
/*   Updated: 2022/05/12 20:50:30 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	health_check(t_philo *th)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == th->nof)
			i = 0;
		if (th->philos_done == th->nof)
			exit(0);
		if (th->philos[i].lte - time_now() > th->ttd)
		{
			print_lock(th, i, "died");
			exit(1);
		}
		i++;
	}

	th = NULL;
}
