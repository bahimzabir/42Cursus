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
	t_philo	*th;

	th = (t_philo *)ph;
	i = 0;
	while (1)
	{
		if (i == th->nof)
			i = 0;
		if (th->philos_done == th->nof)
			ft_exit(0, ph);
		if (time_now() - th->philos[i].lte >= th->ttd
			&& th->philos[i].nte != th->tme)
		{
			th->all_alive = 0;
			printf ("\033[0;31m%ld  philo %d died\033[0m\n",
				timestamp(th), (th->philos[i].id));
			ft_exit(0, ph);
		}
		i++;
	}
	th = NULL;
}
