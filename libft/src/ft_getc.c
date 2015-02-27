/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:17:27 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:17:28 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			ft_getc(int fd)
{
	char		b[1];
	int			ret;

	ret = read(fd, b, 1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	else
		return (*b);
}
