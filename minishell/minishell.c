/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:40:38 by azabir            #+#    #+#             */
/*   Updated: 2022/05/25 14:21:10 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
    char    *inpt;
    int     i;

    i = 0;
    inpt = readline("minishell > ");
    add_history(inpt);
    printf("%s", inpt);
    printf("\n");
    ++i;
    return 0;
}
