/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi2di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:02:21 by azabir            #+#    #+#             */
/*   Updated: 2021/12/21 14:02:23 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

void	ft_bi2di(char	*str)
{
	int	i;
	int	ascii;
	int	power;

	ascii = 0;
	i = 7;
	power = 1;
	while (i >= 0)
	{
		if (str[i] == '1')
			ascii = ascii + power;
		power = power * 2;
		i--;
	}
	write (1, &ascii, 1);
}