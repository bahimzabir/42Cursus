/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:58:23 by azabir            #+#    #+#             */
/*   Updated: 2022/03/24 15:58:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_list *sta, t_list *stb)
{
	int	data;

	data = sta->next->data;
	sta->next->data = sta->data;
	sta->data = data;
	data = stb->next->data;
	stb->next->data = stb->data;
	stb->data = data;
	write (1, "ss\n", 3);
}
