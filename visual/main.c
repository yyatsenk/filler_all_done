/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:10:48 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/15 16:10:51 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int				g_glob = 0;

static int		shape_help(t_data *d, char *str, int fd)
{
	int			i;

	i = 5;
	while (ft_strncmp(str, "Piece", 4))
		get_next_line(fd, &str);
	d->sh_h = ft_atoi(&str[i]);
	while (ft_isdigit(str[++i]))
		;
	d->sh_w = ft_atoi(&str[i]);
	free(str);
	i = -1;
	d->sh = (char**)malloc(sizeof(char*) * (d->sh_h + 1));
	if (d->sh == NULL)
		return (0);
	while (++i < d->sh_h)
	{
		get_next_line(fd, &str);
		d->sh[i] = ft_strdup(str);
		if (d->sh[i] == NULL)
			return (0);
		free(str);
	}
	d->sh[i] = NULL;
	return (1);
}

int				shape_change(t_data *d, int fd, int sinko, t_p *p)
{
	int			i;
	char		*str;

	i = 5;
	sinko = 0;
	str = ft_strdup("a");
	get_next_line(fd, &str);
	if (ft_strncmp(str, "== ", 2) == 0)
		final(d, p, str);
	if (shape_help(d, str, 0) == 0)
		return (0);
	i = -1;
	get_next_line(fd, &str);
	if ((!ft_strncmp(str, "<got (O): [0, 0]", 16)
		|| !ft_strncmp(str, "<got (X): [0, 0]", 16)))
	{
		g_glob = 3;
		shape_change(p->d, 0, 4, p);
		all_ok(p);
		return (0);
	}
	if (str)
		free(str);
	return (0);
}

static int		parser(void *param)
{
	int			res;
	t_p			*p;

	res = 0;
	p = (t_p *)param;
	if (g_glob != 1 && g_glob != 3)
	{
		map_change(p->d, 0, res);
		res = 0;
		res = shape_change(p->d, 0, 4, p);
		all_ok(p);
		map_free(p->d->m);
		shape_free(p->d->sh);
	}
	if (g_glob == 3)
	{
		map_change(p->d, 0, res);
		res = 0;
		res = shape_change(p->d, 0, 4, p);
		all_ok(p);
		map_free(p->d->m);
		shape_free(p->d->sh);
	}
	return (0);
}

static void		p_init(t_p *p)
{
	p->d = NULL;
	p->cof = 50;
	p->mlx_ptr = NULL;
	p->win_ptr = NULL;
	p->c = ' ';
}

int				main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_p			*p;
	t_data		*d;
	t_coords	*sh_coords;

	p = (t_p*)malloc(sizeof(t_p));
	d = (t_data*)malloc(sizeof(t_data));
	sh_coords = (t_coords*)malloc(sizeof(t_coords));
	players_is_set(p);
	map_change(d, 0, 0);
	p_init(p);
	shape_change(d, 0, 4, p);
	visual_run(d, &mlx_ptr, &win_ptr, p);
	all_ok(p);
	mlx_loop_hook(mlx_ptr, parser, (void*)p);
	mlx_loop(mlx_ptr);
	free(p);
	free(d);
	free(sh_coords);
	return (0);
}
