/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:48:18 by azabir            #+#    #+#             */
/*   Updated: 2022/05/21 16:49:07 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_time(t_philo *th, int id, char *action)
{
	sem_wait(th->print_pause);
	printf ("%ld  philo %d %s\n", timestamp(th),
		id, action);
	sem_post(th->print_pause);
}
