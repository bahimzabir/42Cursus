/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:42:16 by azabir            #+#    #+#             */
/*   Updated: 2022/04/27 01:42:18 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_msleep(int time)
{
	time_t	start_time;
	
	start_time = time_now();
	while (time_now() < start_time + time )
	{
		usleep(400);
	}
}
