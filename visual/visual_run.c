/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:15:09 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:15:09 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		make_grid(t_p *p, t_data *d)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j <= (d->m_w * p->cof))
	{
		i = (d->m_h * p->cof) / 15;
		while (++i < (d->m_h * p->cof) + 80)
			mlx_pixel_put(p->mlx_ptr, p->win_ptr, j, i, COLOR_GRID);
		j += p->cof;
	}
	i = (d->m_h * p->cof) / 15;
	while (i <= (d->m_h * p->cof) + (d->m_h * p->cof) / 15)
	{
		j = 0;
		while (++j < (d->m_w * p->cof))
			mlx_pixel_put(p->mlx_ptr, p->win_ptr, j, i, COLOR_GRID);
		i += p->cof;
	}
}

void			visual_run(t_data *d, void **mlx_ptr, void **win_ptr, t_p *p)
{
	p->cof = 50;
	if (d->m_h > 15 && d->m_w > 15)
		p->cof = 25;
	if (d->m_h > 50)
		p->cof = 10;
	*mlx_ptr = mlx_init();
	*win_ptr = mlx_new_window(*mlx_ptr, (d->m_w * p->cof),\
	(d->m_h * p->cof) + (d->m_h * p->cof) / 15, "Filler");
	mlx_string_put(*mlx_ptr, *win_ptr, (d->m_w * p->cof) * 4 / 10,\
	(d->m_h * p->cof) / 15 * 3 / 10, GREEN, "Have a good fight!");
	p->d = d;
	p->mlx_ptr = *mlx_ptr;
	p->win_ptr = *win_ptr;
	make_grid(p, d);
}
