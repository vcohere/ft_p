/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:29:48 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:29:50 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	char		*dest;

	dest = (char *)malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size + 1);
	return (dest);
}
