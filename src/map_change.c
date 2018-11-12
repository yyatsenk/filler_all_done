/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:23:20 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 10:23:21 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
		{
			ft_printf("0 0\n");
			exit(1);
		}
		free(str);
	}
	d->m[i] = NULL;
}

void			map_change(t_data *d, int fd)
{
	char		*str;
	int			i;

	str = NULL;
	i = 7;
	get_next_line(fd, &str);
	d->m_h = ft_atoi(&str[i]);
	while (ft_isdigit(str[++i]))
		;
	d->m_w = ft_atoi(&str[i]);
	free(str);
	i = -1;
	d->m = (char**)malloc(sizeof(char*) * (d->m_h + 1));
	if (d->m == NULL)
	{
		ft_printf("0 0\n");
		exit(1);
	}
	map_change_help(d);
}
