/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:29:02 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:29:02 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strncpy(char *dest, char const *src, size_t len)
{
	int			i;

	i = 0;
	while (src[i] && len)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	return (dest);
}
