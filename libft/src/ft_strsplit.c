/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:43:55 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:43:59 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_countword(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (j);
}

static char		**ft_createsplit(char const *s, char c, char **newtab)
{
	int			len;
	int			start;
	int			i;

	len = 0;
	start = 0;
	i = 0;
	while (s[len] != '\0')
	{
		if (s[len] != c)
		{
			start = len;
			while (s[len] != c && s[len] != '\0')
				len++;
			newtab[i++] = ft_strsub(s, start, (len - start));
		}
		else
			while (s[len] == c && s[len] != '\0')
				len++;
		newtab[i] = NULL;
	}
	return (newtab);
}

char			**ft_strsplit(char const *s, int c)
{
	char		**tab;

	if (!s)
	{
		if (c != ' ')
		{
			if (!(tab = (char **)malloc(sizeof(char *) * 1)))
				return (NULL);
			tab[0] = NULL;
			return (tab);
		}
		return (NULL);
	}
	else if (!c)
		return ((char **)ft_strdup(s));
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_countword(s, c) + 1))))
		return (NULL);
	tab = ft_createsplit(s, c, tab);
	return (tab);
}
