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

void	putbit(int sign)
{
	static int	i = 0;
	char		code[7];

	if (sign == SIGUSR1)
		code[i] = '1';
	else if (sign == SIGUSR2)
		code[i] = '0';
	i += 1;
	if (i == 8)
	{
		ft_bi2di(code);
		i = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write (1, "\n", 1);
	signal(SIGUSR1, putbit);
	signal(SIGUSR2, putbit);
	while (1)
		pause();
}
