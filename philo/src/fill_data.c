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
	int	i;

	i = 1;
	if (arv[i])
		(*data).nof = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).ttd = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tte = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tts = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tme = ft_atoi(arv[i]);
	else
		(*data).tme = 2147483647;
	
}
