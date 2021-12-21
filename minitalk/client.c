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
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char *str, char *buf);

int main(int argc, char **argv)
{
	int bit = 0;
	int i = 0;
	int j = 8;

	argv[2] = ft_strjoin(argv[2], "\n");
	while (argv[2][i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (argv[2][i] & (1 << bit))
			{
				kill(atoi(argv[1]), SIGUSR1);
				write(1, "1", 1);
				usleep(50);
			}
			else
			{
				kill(atoi(argv[1]), SIGUSR2);
				write(1, "0", 1);
				usleep(50);
			}
			bit--;
		}
		write(1, "\n", 1);
		i++;
	}
	i = 8;
}