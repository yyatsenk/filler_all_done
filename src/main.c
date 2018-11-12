/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:19:10 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 10:19:11 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		map_free(char **m)
{
	int			i;

	i = -1;
	while (m && m[++i])
		free(m[i]);
	free(m[i]);
	free(m);
}

static void		shape_free(char **sh)
{
	int			i;

	i = -1;
	while (sh && sh[++i])
		free(sh[i]);
	free(sh[i]);
	free(sh);
}

static void		algo0(t_data *d, t_coords *sh_coords, int fd)
{
	while (play0(d, sh_coords))
	{
		map_free(d->m);
		shape_free(d->sh);
		map_change(d, fd);
		shape_change(d, fd);
	}
}

static void		algo1(t_data *d, t_coords *sh_coords, int fd)
{
	while (play1(d, sh_coords))
	{
		map_free(d->m);
		shape_free(d->sh);
		map_change(d, fd);
		shape_change(d, fd);
	}
}

int				main(void)
{
	t_data		*d;
	t_coords	*sh_coords;

	d = (t_data*)malloc(sizeof(t_data));
	sh_coords = (t_coords*)malloc(sizeof(t_coords));
	player_num(0, d);
	map_change(d, 0);
	shape_change(d, 0);
	find_my_coords(d);
	if (d->way == 1 || d->way == 0)
		algo0(d, sh_coords, 0);
	else
		algo1(d, sh_coords, 0);
	map_free(d->m);
	shape_free(d->sh);
	free(d);
	free(sh_coords);
	return (0);
}
