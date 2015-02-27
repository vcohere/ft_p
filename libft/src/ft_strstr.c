/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:30:56 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:30:57 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	char		*s;

	s = (char *)s1;
	while (*s++)
		if (ft_strnequ(s, s2, ft_strlen(s2)))
			return (s);
	return (NULL);
}
