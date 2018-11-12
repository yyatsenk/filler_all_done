/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:25:04 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 10:25:07 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			norm0(t_data *d, t_coords *sh_c)
{
	while (d->sh[sh_c->y] && d->sh[sh_c->y][sh_c->x] != '*')
	{
		sh_c->x++;
		if (d->sh[sh_c->y][sh_c->x] == '\0')
		{
			sh_c->y++;
			sh_c->x = 0;
		}
	}
}

int				norm1(t_data *d, t_coords *sh_c, int n_c, int n_r)
{
	char		en;

	if (d->s == 'O')
		en = 'X';
	else
		en = 'O';
	if ((d->l_c + d->sh_w) >= d->m_w
	|| (d->l_r + d->sh_h) >= d->m_h)
		return (0);
	if ((d->l_c + sh_c->x - n_c) >= 0 && (d->l_r + sh_c->y - n_r) >= 0
		&& (d->l_c + sh_c->x - n_c) <= (d->m_w - 1)
		&& (d->l_r + sh_c->y - n_r) <= (d->m_h - 1)
		&& (d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] == d->s
		|| d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] == '.'
		|| d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] == d->s + 32)
		&& d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] != en
		&& d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] != en + 32)
		return (1);
	else
		return (0);
}

void			norm2(t_data *d, t_coords *sh_c, int n_c, int n_r)
{
	if ((d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] == d->s
		|| d->m[d->l_r + sh_c->y - n_r][d->l_c + sh_c->x - n_c] == d->s + 32))
		d->num_of_sign++;
	if (d->sh[sh_c->y][sh_c->x + 1] == '\0' && !(sh_c->x = 0))
		sh_c->y++;
	else
		sh_c->x++;
}

int				norm3(t_data *d, int n_c, int n_r)
{
	if (d->l_c - n_c < 0 || d->l_r - n_r < 0
		|| d->num_of_sign != 1)
		return (0);
	d->l_c = d->l_c - n_c;
	d->l_r = d->l_r - n_r;
	return (1);
}

int				ft_is_possible(t_data *d, t_coords *sh_c, int n_c, int n_r)
{
	int			i;
	int			stars_num;

	i = -1;
	d->num_of_sign = 0;
	sh_c->y = 0;
	sh_c->x = 0;
	stars_num = num_of_stars(d);
	while (++i < stars_num)
	{
		norm0(d, sh_c);
		if (d->sh[sh_c->y][sh_c->x] == '*' && i == 0)
		{
			n_c = sh_c->x;
			n_r = sh_c->y;
		}
		if (norm1(d, sh_c, n_c, n_r))
			norm2(d, sh_c, n_c, n_r);
		else
			return (0);
	}
	if (norm3(d, n_c, n_r) == 0)
		return (0);
	return (1);
}
