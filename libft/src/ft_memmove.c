/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:22:09 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:22:11 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void			*ft_memmove(void *s1, const void *s2, size_t len)
{
	void		*cpy;

	cpy = (void *)malloc(len);
	ft_memcpy(cpy, s2, len);
	ft_memcpy(s1, cpy, len);
	free(cpy);
	return (s1);
}
