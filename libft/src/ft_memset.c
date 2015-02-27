/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:22:22 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:22:24 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*dest;

	dest = (unsigned char *)b;
	while (len--)
		*dest++ = (unsigned char)c;
	return (b);
}
