/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:20:47 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:20:49 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	unsigned char		*s;

	dest = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		*dest++ = (unsigned char)*s++;
		n--;
	}
	return (dst);
}
