/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:30:52 by azabir            #+#    #+#             */
/*   Updated: 2021/12/20 11:30:54 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

char *str;

void	outzero(int i)
{
	i = 0;
	//write(1, "0", 2);
	str = ft_strjoin(str, "0");
}
void	outone(int j)
{
	j = 0;
	str = ft_strjoin(str, "1");
}

int	main(void)
{
	ft_putnbr(getpid());
	write (1, "\n", 1);
	signal(SIGUSR1, outone);
	signal(SIGUSR2, outzero);
	
	while (1)
	{
		if (str && ft_strlen(str) == 8)
		{
			ft_bi2di(str);
			free(str);
			str = (char *)ft_calloc(1, 1);
		}
		pause();
	}
}
