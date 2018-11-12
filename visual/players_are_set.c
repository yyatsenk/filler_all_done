/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_are_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:17:31 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:17:32 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static char		*setplayer(char *str)
{
	int			i;
	int			j;
	int			i_need;
	char		*res;
	int			k;

	j = 0;
	i = -1;
	k = 0;
	while (str[++i] && ft_strncmp(&str[i], ".filler", 5))
		;
	j = i - 1;
	while (str[j] != '/')
		j--;
	j++;
	i_need = i - j;
	res = (char*)malloc(sizeof(char) * (i_need + 1));
	while (j < i)
	{
		res[k] = str[j];
		j++;
		k++;
	}
	res[k] = '\0';
	return (res);
}

void			players_is_set(t_p *p)
{
	char		*str;
	int			k;

	k = 10;
	str = NULL;
	while (--k)
	{
		get_next_line(0, &str);
		if (!ft_strncmp(str, "$$$ exec p1 :", 13))
			p->player1 = setplayer(str);
		if (!ft_strncmp(str, "$$$ exec p2 :", 13))
			p->player2 = setplayer(str);
		free(str);
	}
}
