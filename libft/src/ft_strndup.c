/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:29:16 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:29:17 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char			*ft_strndup(char const *s, size_t len)
{
	char			*dest;

	dest = (char *)malloc(sizeof(char) * len + 1);
	dest = ft_strncpy(dest, s, len);
	return (dest);
}
