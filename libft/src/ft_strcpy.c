/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:25:58 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:26:01 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strcpy(char *dest, char const *src)
{
	char		*d;
	char		*s;

	d = (char *)dest;
	s = (char *)src;
	while ((*d++ = *s++))
		;
	return (dest);
}
