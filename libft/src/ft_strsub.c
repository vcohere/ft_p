/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:31:15 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:31:16 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	int				j;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL || start > ft_strlen(s) || len > ft_strlen(s) - start)
		return (NULL);
	while (i < start)
		i++;
	while (i < len + start)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
