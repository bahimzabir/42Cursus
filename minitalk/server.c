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

char	*g_str;

void	outzero(int i)
{
	i = 0;
	g_str = ft_strjoin(g_str, "0");
}

void	outone(int j)
{
	j = 0;
	g_str = ft_strjoin(g_str, "1");
}

int	main(void)
{
	ft_putnbr(getpid());
	write (1, "\n", 1);
	signal(SIGUSR1, outone);
	signal(SIGUSR2, outzero);
	while (1)
	{
		if (g_str && ft_strlen(g_str) == 8)
		{
			ft_bi2di(g_str);
			free(g_str);
			g_str = (char *)ft_calloc(1, 1);
		}
		pause();
	}
}
