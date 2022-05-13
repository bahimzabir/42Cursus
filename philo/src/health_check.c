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

void	*health_check(void *ph)
{
	int		i;
	t_philo *th;
	th = (t_philo *)ph;
	i = 0;
	while (1)
	{
		if (i == th->nof)
			i = 0;
		if (th->philos_done == th->nof)
			exit(0);
		if (time_now() - th->philos[i].lte >= th->ttd && th->philos[i].nte != th->tme)
		{
			print_lock(th, i, "died");
			exit(1);
		}
		i++;
	}
	th = NULL;
}
