/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:48:27 by azabir            #+#    #+#             */
/*   Updated: 2022/04/16 18:49:06 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(t_list **sta, t_list **stb)
{
	if ((*stb) && (*sta) && (*stb)->next && (*sta)->next
		&& (*stb)->next->index - (*stb)->index == 1 && (*sta)->next->index - (*sta)->index == -1)
		ft_ss(sta, stb);
	else if((*sta) && (*sta)->next && (*sta)->next->index - (*sta)->index == -1)
		ft_sa(sta);
	else if((*stb) && (*stb)->next && (*stb)->next->index - (*stb)->index == 1)
		ft_sb(stb);
}

