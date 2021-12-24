/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:30:39 by azabir            #+#    #+#             */
/*   Updated: 2021/12/20 11:30:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	sig_handler(int pid, char	*str)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (str[i] & (1 << bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("PID error !\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("PID error !\n");
			}
			usleep(600);
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 3)
		ft_error ("[WRONG FARMAT]!\nHint: ./client {pid} {String}\n");
	str = ft_join(argv[2], "\n");
	sig_handler(ft_atoi(argv[1]), str);
	free (str);
}
