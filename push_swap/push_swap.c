/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:33:22 by azabir            #+#    #+#             */
/*   Updated: 2022/03/20 17:34:16 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(char **arr, t_list **stack_list)
{
	int	i;

	i = 2;
	*stack_list = lstmake (ft_atoi(arr[1]));
	while (arr [i])
	{
		lstaddback(*stack_list, ft_atoi(arr[i]));
		i++;
	}
}

void ft_push(t_list **sta, t_list **stb)
{
	//*sta = *stb;
	ft_pa(sta, stb);
}

void	ft_move(t_list **stack, int ref)
{
	if (ref == 01)
		ft_sa(*stack);
}

int	main(int arc, char **arv)
{
	t_list	*sta;
	t_list	*stb;
	
	if (arc <= 1)
		return (1);
	arr_to_list(arv, &stb);
	arr_to_list(arv, &sta);
	ft_move(&sta, 01);
	ft_push(&stb, &sta);
	while (sta->next != NULL)
	{
		printf("%d\n", sta->data);
		sta = sta->next;
	}
	printf("%d\n######\n", sta->data);
	while (stb->next != NULL)
	{
		printf("%d\n", stb->data);
		stb = stb->next;
	}
	printf("%d", stb->data);
	return (0);
}
