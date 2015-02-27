/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:19:59 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:20:00 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t len)
{
	void			*dest;

	dest = (void *)malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, len);
	return (dest);
}
