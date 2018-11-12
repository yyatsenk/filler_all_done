/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:16:06 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:16:07 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		map_change_help(t_data *d)
{
	char		*str;
	int			i;
	int			fd;

	str = NULL;
	i = -1;
	fd = 0;
	get_next_line(fd, &str);
	free(str);
	while (++i < d->m_h)
	{
		get_next_line(fd, &str);
		d->m[i] = ft_strsub(str, 4, d->m_w);
		if (d->m[i] == NULL)
			return ;
		free(str);
	}
	d->m[i] = NULL;
	i = -1;
}

int				map_change(t_data *d, int fd, int res)
{
	char		*str;
	int			i;
	int			k;

	str = ft_strdup("a");
	k = -1;
	i = 7;
	res = 0;
	while (ft_strncmp(str, "Plateau", 5))
	{
		free(str);
		get_next_line(fd, &str);
	}
	d->m_h = ft_atoi(&str[i]);
	while (ft_isdigit(str[++i]))
		;
	d->m_w = ft_atoi(&str[i]);
	free(str);
	i = -1;
	d->m = (char**)malloc(sizeof(char*) * (d->m_h + 1));
	if (d->m == NULL)
		return (0);
	map_change_help(d);
	return (1);
}
