/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:43:56 by azabir            #+#    #+#             */
/*   Updated: 2022/04/21 12:43:58 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	*ft_forks(int nof)
{
	int	*i;
	int	j;

	i = malloc(sizeof(int) * nof);
	j = 0;
	while (j < nof)
	{
		i[j] = 1;
		j++;
	}
	return (i);
}
