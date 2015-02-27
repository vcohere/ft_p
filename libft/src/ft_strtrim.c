/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:31:30 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:31:31 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strtrim(char const *s)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len]))
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
