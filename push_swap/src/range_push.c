/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:46:07 by azabir            #+#    #+#             */
/*   Updated: 2022/04/04 16:46:44 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_push(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	int		c;

	// i = 30 is give 6000 in 500 and i = 10 and i += 9 gives 700 in 100 the best so far;
	i = 30;
	j = 1;
	c = 0;
	while (!(*stb) && !check_order(*sta))
	{
		while (i <= arc / 2 && !check_order(*sta))
		{
			if ((*sta)->index >= arc / 2 - i && (*sta)->index <= arc / 2 + i - 1 )
				ft_pb(sta, stb);
			else if ((*sta)->index <= i + 1)
				{
					ft_pb(sta, stb);
					ft_rb(stb);
				}
			else
				ft_ra(sta);
			if ((*stb) && (*stb)->index <= arc / 4)
				ft_rb(stb);
			if (j == arc || !check_range(*sta, i, arc))
			{
				i = i + 20;
				if (i >= arc / 2)
					i = arc / 2;
				j = 0;
			}
			j++;
		}
		while (*stb)
		{
			if ((*sta)->index - (*stb)->index == 1)
				ft_pa(sta, stb);
			else
				fast_move(stb, sta, list_counter(*stb));
		}
	}
}

