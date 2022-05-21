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

void	print_time(t_philo *th,int id, char *action)
{
	if (th->all_alive)
	{
		printf ("\033[0;34m%ld \033[0m philo %d %s\n", timestamp(th),
			id, action);
	}
}
