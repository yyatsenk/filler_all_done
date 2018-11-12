/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:27:50 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/15 17:27:51 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "../ft_printf/ft_printf.h"
# define COLOR_GRID 0x00555555
# define RED 0x00C00000
# define PINK 0x00FF8585
# define GREEN 0x0000C000
# define LIGHT_GR 0x0085FF85

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

typedef struct	s_pp
{
	t_data		*d;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*player1;
	char		*player2;
	int			cof;
	char		c;
}				t_p;
void			visual_run(t_data *d, void **mlx_ptr, void **win_ptr, t_p *p);
int				shape_change(t_data *d, int fd, int sinko, t_p *p);
void			players_is_set(t_p *p);
int				map_change(t_data *d, int fd, int res);
void			all_ok(t_p *p);
void			shape_free(char **sh);
void			map_free(char **m);
void			final(t_data *d, t_p *p, char *str);
#endif
