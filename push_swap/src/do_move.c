/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:49:30 by azabir            #+#    #+#             */
/*   Updated: 2022/03/28 15:49:35 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move(t_list **sta, t_list **stb)
{
	int	i;

	i = 0;
	if ((*stb && (*stb)->next))
		if ((*stb)->next->index > (*stb)->index)
			i = 2;
	if ((*sta)->index - (*sta)->next->index == 1)
			i++;
	return (i);
}

void	do_move(t_list **sta, t_list **stb, int	arc, int i)
{
	int		index;
	int		count;
	t_list	*temp;

	temp = *sta;
	count = 1;
	index =  temp->index + 1;

	
	if (ft_move(sta, stb) == 1)
		ft_sa(sta);
	else if (ft_move(sta, stb) == 2)
		ft_sb(stb);
	else if (ft_move(sta, stb) == 3)
		ft_ss(sta, stb);
	while (temp->index != i)
	{
		temp = temp->next;
		count++;
	}
	if (count > (arc / 2) + 1)
		while ((*sta)->index != i)
			ft_rra(sta);
	else
		while ((*sta)->index != i)
			ft_ra(sta);
	if (temp->index == arc)
	{
		ft_ra(sta);
		temp = *sta;
	}
}
// void	do_move(t_list **sta, t_list **stb, int	arc, int i)
// {
// 	int		index;
// 	int		count;
// 	t_list	*temp;

// 	temp = *sta;
// 	count = 1;
// 	index =  temp->index + 1;

// 	if (ft_move(sta, stb) == 1)
// 		ft_sa(sta);
// 	else if (ft_move(sta, stb) == 2)
// 		ft_sb(stb);
// 	else if (ft_move(sta, stb) == 3)
// 		ft_ss(sta, stb);
// 	while (temp->index != i)
// 	{
// 		temp = temp->next;
// 		count++;
// 	}
// 	//printf ("\n count = %d || arc/2 = %d \n", count, arc/2 );
// 	if (count >= (arc / 2))
// 		while ((*sta)->index != i)
// 			ft_rra(sta);
// 	else
// 		while ((*sta)->index != i)
// 			ft_ra(sta);
// }
