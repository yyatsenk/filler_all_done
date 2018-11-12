/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:28:42 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 10:28:43 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				play0(t_data *d, t_coords *sh_coords)
{
	int			i;

	i = 0;
	d->l_c = d->m_w - 1;
	d->l_r = d->m_h - 1;
	while (i != 1)
	{
		if ((i = ft_is_possible(d, sh_coords, 0, 0)))
			ft_printf("%d %d\n", d->l_r, d->l_c);
		else
		{
			if ((d->l_r == 0 && d->l_c == 0))
			{
				ft_printf("%d %d\n", 0, 0);
				return (0);
			}
			else if (d->l_c == 0 && d->l_r > 0 && (d->l_c = d->m_w - 1))
				d->l_r--;
			else if (d->l_c != 0)
				d->l_c--;
		}
	}
	return (1);
}
