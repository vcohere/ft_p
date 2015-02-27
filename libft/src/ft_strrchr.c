/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:30:21 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:30:22 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strrchr(char const *s, int c)
{
	char		*save;
	char		*dest;

	save = NULL;
	dest = (char *)s;
	if (!s)
		return (0);
	while (*dest)
	{
		if (*dest == c)
			save = dest;
		dest++;
	}
	return (save);
}
