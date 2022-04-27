/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:45:40 by azabir            #+#    #+#             */
/*   Updated: 2022/04/27 01:45:41 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

time_t	timestamp(t_philo *phi)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000) - phi->inittime);
}
