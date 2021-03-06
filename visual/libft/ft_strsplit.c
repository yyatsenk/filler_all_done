/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:32:23 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/08/04 14:01:26 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_until(const char *str, char c)
{
	const char	*s;

	s = str;
	while (*s != c && *s)
		++s;
	return (s - str);
}

static int		word_count(char const *s, char c)
{
	int			i;
	int			wc;
	int			found;

	i = 0;
	wc = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = 0;
		else
		{
			if (found == 0)
				wc++;
			found = 1;
		}
		i++;
	}
	return (wc);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**table;
	int			size;
	int			i;
	int			substr_len;

	if (!s)
		return (0);
	size = word_count(s, c);
	substr_len = 0;
	i = 0;
	if (!(table = (char **)malloc((sizeof(char *) * size + 1))))
		return (NULL);
	while (size--)
	{
		while (*s == c && *s != '\0')
			s++;
		substr_len = ft_strlen_until(s, c);
		table[i] = ft_strncpy(ft_strnew(substr_len), s, substr_len);
		if (!table[i])
			return (NULL);
		s += substr_len;
		i++;
	}
	table[i] = NULL;
	return (table);
}
