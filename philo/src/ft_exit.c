/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:20:24 by azabir            #+#    #+#             */
/*   Updated: 2022/04/19 10:20:26 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(int i, t_philo *th)
{
	
	sem_unlink("sem_1");
	if (i == 1)
	{
		write (1, "Error\n", 6);
		exit (i);
	}
	pthread_detach(th->health);
	//system("leaks philo");
	exit(i);
}
