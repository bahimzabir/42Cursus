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

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

char *str;
void ft_bi2di(char	*str);
char	*ft_strjoin(char *str, char *buf);

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
	printf("%d\n", getpid());
	signal(SIGUSR1, outone);
	signal(SIGUSR2, outzero);
	
	while (1)
	{
		if (str && strlen(str) == 8)
		{
			//printf("%s\n", str);
			ft_bi2di(str);
			str = strdup("\0");
		}
		pause();
	}
}
