/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:19:01 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:19:02 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		win_keys(int keycode, void *param)
{
	t_p			*p;

	p = (t_p*)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void			final(t_data *d, t_p *p, char *str)
{
	int			num1;
	int			num2;

	d->way = 0;
	ft_printf("%s\n", str);
	num1 = ft_atoi(&str[10]);
	free(str);
	get_next_line(0, &str);
	num2 = ft_atoi(&str[10]);
	ft_printf("%s\n", str);
	free(str);
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, 400, 400, "Winner");
	if (num1 > num2)
		mlx_string_put(p->mlx_ptr, p->win_ptr, 150,\
		150, GREEN, ft_strjoin(p->player1, " won!!!"));
	else if (num1 < num2)
		mlx_string_put(p->mlx_ptr, p->win_ptr, 150,\
		150, GREEN, ft_strjoin(p->player2, " won!!!"));
	else
		mlx_string_put(p->mlx_ptr, p->win_ptr, 150, 150, PINK, "Drawn");
	mlx_key_hook(p->win_ptr, win_keys, (void*)p);
	mlx_loop(p->mlx_ptr);
}
