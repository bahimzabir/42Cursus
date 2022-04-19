/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:48:21 by azabir            #+#    #+#             */
/*   Updated: 2022/04/18 20:48:23 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_data(t_philo *data, char	**arv)
{
	int	i;

	i = 1;
	if (arv[i])
		(*data).nof == ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).ttd == ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tte == ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tts == ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tme == ft_atoi(arv[i]);
}

int	main(int arc, char **arv)
{
	t_philo	data;
	if (arc == 6 || arc == 5)
	{
		fill_data(&data, arv);
	}
}
