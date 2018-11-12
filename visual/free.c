/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:45:50 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/02/19 11:45:52 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			map_free(char **m)
{
	int			i;

	i = -1;
	if (!m || !*m)
		return ;
	while (m && m[++i])
		free(m[i]);
	free(m[i]);
	free(m);
}

void			shape_free(char **sh)
{
	int			i;

	i = -1;
	if (!sh || !*sh)
		return ;
	while (sh && sh[++i])
		free(sh[i]);
	free(sh[i]);
	free(sh);
}
