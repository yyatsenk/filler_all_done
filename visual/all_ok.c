/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:14:08 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:14:10 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		drow_cell(t_p *p, int i, int j, t_data *d)
{
	int			x;
	int			y;
	int			y_min;
	int			x_min;

	y = (j * p->cof) + (d->m_h * p->cof) / 15;
	y_min = y;
	while (++y < (y_min + p->cof))
	{
		x = i * p->cof;
		x_min = x;
		while (++x < x_min + p->cof)
		{
			if (p->c == 'O')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, GREEN);
			else if (p->c == 'X')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, RED);
			else if (p->c == 'o')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, LIGHT_GR);
			else if (p->c == 'x')
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, PINK);
		}
	}
}

void			all_ok(t_p *p)
{
	int			i;
	int			j;

	i = -1;
	while (p->d->m[++i])
	{
		j = -1;
		while (p->d->m[i][++j])
		{
			if (p->d->m[i][j] == 'O' && (p->c = 'O'))
				drow_cell(p, j, i, p->d);
			else if (p->d->m[i][j] == 'X' && (p->c = 'X'))
				drow_cell(p, j, i, p->d);
			else if (p->d->m[i][j] == 'o' && (p->c = 'o'))
				drow_cell(p, j, i, p->d);
			else if (p->d->m[i][j] == 'x' && (p->c = 'x'))
				drow_cell(p, j, i, p->d);
		}
	}
}
