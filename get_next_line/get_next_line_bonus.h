/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:59:55 by azabir            #+#    #+#             */
/*   Updated: 2021/12/04 12:00:40 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_nl_check(char *str);
size_t	ft_strlen(char	*str);
char	*ft_strjoin(char *str, char *buf);
char	*ft_line(char *s1);
char	*ft_rm_line(char *str);
char	*get_next_line(int fd);

#endif
