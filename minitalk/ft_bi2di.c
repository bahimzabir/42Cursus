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
#include<unistd.h>

void ft_bi2di(char	*str)
{
	int	i;
	int j;
	int ascii;
	int power;

	ascii = 0;
	if (str[7] == '1')
		ascii = 1;
	i = 0;
	while (i <= 6)
	{
		if (str[i] == '1')
		{
			power = 1;
			j = 6;
			while (j >= i)
			{
				power = power * 2;
				j--;
			}
			ascii += power;
		}
		i++;
	}
	write (1, &ascii, 1);
}
