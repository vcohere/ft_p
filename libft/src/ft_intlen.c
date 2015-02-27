/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:17:48 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:17:49 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_intlen(int number)
{
	int			i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = -number;
		i = 1;
	}
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}
