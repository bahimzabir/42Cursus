/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:27:09 by azabir            #+#    #+#             */
/*   Updated: 2022/04/08 17:27:13 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "stdio.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return(0);
		i++;
	}
	return (1);
}

void	moves_handler(t_list **sta, t_list **stb, char *move)
{
	if (ft_strcmp(move, "sa\n"))
		ft_sa(sta);
	else if (ft_strcmp(move, "sb\n"))
		ft_sb(stb);
	else if (ft_strcmp(move, "ss\n"))
		ft_ss(sta, stb);
	else if (ft_strcmp(move, "ra\n"))
		ft_ra(sta);
	else if (ft_strcmp(move, "rb\n"))
		ft_rb(stb);
	else if (ft_strcmp(move, "rr\n"))
		ft_rr(sta, stb);
	else if (ft_strcmp(move, "rra\n"))
		ft_rra(sta);
	else if (ft_strcmp(move, "rrb\n"))
		ft_rrb(stb);
	else if (ft_strcmp(move, "rrr\n"))
		ft_rrr(sta, stb);
	else if (ft_strcmp(move, "pa\n"))
		ft_pa(sta, stb);
	else if (ft_strcmp(move, "pb\n"))
		ft_pb(sta, stb);
	else
		ft_exit();
}

int	main(int arc, char **arv)
{
	t_list 	*sta;
	t_list 	*stb;
	char	*line;

	arr_to_list(arv, &sta);
	indexing(&sta, arc);
	line = g_nl(0);
	while (line)
	{
		moves_handler (&sta, &stb, line);
		line = g_nl(0);
	}
	if (check_order(sta))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
