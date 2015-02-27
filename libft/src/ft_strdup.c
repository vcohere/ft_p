/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:26:29 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:26:30 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char				*ft_strdup(const char *str)
{
	char		*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	dest = ft_strcpy(dest, str);
	return (dest);
}
