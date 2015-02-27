/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:20:08 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:20:10 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		*(dest + i) = *(srce + i);
		if (*(srce + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
