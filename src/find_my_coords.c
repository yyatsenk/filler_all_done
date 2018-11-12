/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_my_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:26:45 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 10:26:46 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		algo_defind(t_data *d, t_coords sign_c)
{
	if (sign_c.x < (d->m_w / 2) && sign_c.y < (d->m_h / 2))
		d->way = right_down;
	else if (sign_c.x > (d->m_w / 2) && sign_c.y < (d->m_h / 2))
		d->way = left_down;
	else if (sign_c.x < (d->m_w / 2) && sign_c.y > (d->m_h / 2))
		d->way = right_up;
	else if (sign_c.x > (d->m_w / 2) && sign_c.y >= (d->m_h / 2))
		d->way = left_up;
	else
		d->way = right_down;
}

void			find_my_coords(t_data *d)
{
	t_coords	m;
	t_coords	sign_c;

	m.y = 0;
	while (m.y < d->m_h)
	{
		m.x = 0;
		while (m.x < d->m_w)
		{
			if (d->m[m.y][m.x] == d->s)
			{
				sign_c.x = m.x;
				sign_c.y = m.y;
			}
			m.x++;
		}
		m.y++;
	}
	algo_defind(d, sign_c);
}
