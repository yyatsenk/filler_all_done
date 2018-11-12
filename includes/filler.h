/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:29:00 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/06 16:29:02 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum	e_way_definder
{
	right_down,
	left_down,
	right_up,
	left_up,
}				t_w_def;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_data
{
	char		**m;
	int			m_h;
	int			m_w;
	t_w_def		way;
	char		**sh;
	int			sh_h;
	int			sh_w;
	char		s;
	int			l_c;
	int			l_r;
	int			num_of_sign;
}				t_data;

int				num_of_stars(t_data *d);
void			find_my_coords(t_data *d);
int				ft_is_possible(t_data *d, t_coords *sh_c, int n_c, int n_r);
void			map_change(t_data *d, int fd);
int				play0(t_data *d, t_coords *sh_coords);
int				play1(t_data *d, t_coords *sh_coords);
int				num_of_stars(t_data *d);
void			shape_change(t_data *d, int fd);
void			player_num(int fd, t_data *d);
#endif
