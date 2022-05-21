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
	id = *(th->index);
	free (th->index);
	while (1)
	{
		if(time_now() - th->last_meal >= th->ttd)
		{
			print_time(th, id, "died");
			exit(1);
		}
	}
	return(NULL);
}
