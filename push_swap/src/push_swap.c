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

		/*make a fun that check the best one (ra or rra),
		 try to work on any number of data then try to make (ss & rr & rrr) useful AF*/
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

void	print_list(t_list *tmp)
{
	printf("-----------------\n");
	if (tmp)
	{
		while (tmp)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
	printf("\n-----------------\n");
}
void	print_index(t_list *tmp)
{
	if (tmp)
	{
		while (tmp)
		{
			printf("%d\n", tmp->index);
			tmp = tmp->next;
		}
	}
	printf("\n#####\n");
}
void	push_swap(t_list **sta, t_list **stb, int arc)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (check_order(*sta))
	{
		while(i++ < (arc / 2) + 1)
			ft_pb(sta, stb);
		while(sta)

	}

}
/*void	push_swap(t_list **sta, t_list **stb, int arc)
{
	int		i;
	int		j;
	t_list	*temp;

	temp = *sta;
	i = 1;
	j = 0;
	while (i <= arc)
	{
		
		while (((*sta)->index != i) && (check_order(*sta) == 0))
			do_move(sta, arc, i);
		if ((i == arc || check_order(*sta) == 1) && !(*stb))
			break;
		if (check_order(*sta) == 0)
			ft_pb(sta, stb);
		i++;
		if (i == arc && check_order(*sta) == 1)
			while (i >= 1)
			{
				ft_pa(sta, stb);
				i--;
			}
		if (i == 0)
			break;
	}
}
*/
int	main(int arc, char **arv)
{
	t_list	*sta;
	t_list	*stb;

	stb = NULL;
	if (arc <= 1)
		return (1);
	arr_to_list(arv, &sta);
	indexing(&sta, arc);
	push_swap(&sta, &stb, arc - 1);
	//print_list(sta);
	return (0);
}