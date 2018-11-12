/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:43:38 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/05 13:43:40 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				num_of_stars(t_data *d)
{
	int			stars;
	int			i;
	int			j;

	stars = 0;
	i = 0;
	while (d->sh && d->sh[i])
	{
		j = 0;
		while (d->sh[i][j])
		{
			if (d->sh[i][j] == '*')
				stars++;
			j++;
		}
		i++;
	}
	return (stars);
}

void			shape_change(t_data *d, int fd)
{
	int			i;
	char		*str;

	i = 5;
	str = NULL;
	get_next_line(fd, &str);
	d->sh_h = ft_atoi(&str[i]);
	while (ft_isdigit(str[++i]))
		;
	d->sh_w = ft_atoi(&str[i]);
	free(str);
	i = -1;
	d->sh = (char**)malloc(sizeof(char*) * (d->sh_h + 1));
	if (d->sh == NULL)
	{
		ft_printf("0 0\n");
		exit(1);
	}
	while (++i < d->sh_h)
	{
		get_next_line(fd, &str);
		d->sh[i] = ft_strdup(str);
		free(str);
	}
	d->sh[i] = NULL;
}

void			player_num(int fd, t_data *d)
{
	char		*str;

	str = NULL;
	get_next_line(fd, &str);
	if (str && str[10] == '1')
		d->s = 'O';
	else if (str && str[10] == '2')
		d->s = 'X';
	free(str);
}
