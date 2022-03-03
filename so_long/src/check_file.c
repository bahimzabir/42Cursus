/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:28:22 by azabir            #+#    #+#             */
/*   Updated: 2022/03/03 02:28:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	check_file(char *path)
{
	int		j;
	int		i;
	char	*ber;

	j = 3;
	i = 0;
	ber = ".ber";
	if (ft_strlen(path) <= 4)
		return (0);
	while (path[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (ber[j] != path[i])
			return (0);
		j--;
		i--;
	}
	return (1);
}
