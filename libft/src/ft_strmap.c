/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:28:08 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:28:11 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	while (s[i])
	{
		temp[i] = f(s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
