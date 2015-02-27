/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:25:07 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:25:08 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strchr(char const *s, int c)
{
	char		*str;
	int			i;

	str = (char *)s;
	i = -1;
	while (str[++i])
		if (*str == c)
			return (str);
	return (0);
}
