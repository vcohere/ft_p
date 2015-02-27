/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:20:20 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:20:22 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	char		*str;

	str = (char *)s;
	while (n)
	{
		if (*str == (char)c)
			return (str);
		str++;
		n--;
	}
	return (0);
}
