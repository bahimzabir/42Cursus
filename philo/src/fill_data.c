/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:43:24 by azabir            #+#    #+#             */
/*   Updated: 2022/04/21 12:43:26 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	fill_data(t_philo *data, char	**arv)
{
	if (arv[1])
		(*data).nof = ft_atoi(arv[1]);
	if ((*data).nof <= 1)
	{
		printf("0: philo 1 died\n");
		exit(1);
	}
	if (arv[2])
		(*data).ttd = ft_atoi(arv[2]);
	if (arv[3])
		(*data).tte = ft_atoi(arv[3]);
	if (arv[4])
		(*data).tts = ft_atoi(arv[4]);
	if (arv[5])
		(*data).tme = ft_atoi(arv[5]);
	else
		(*data).tme = 2147483647;
}
