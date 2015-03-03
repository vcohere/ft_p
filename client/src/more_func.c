/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:07:24 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/03 04:07:25 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\nUse \"quit\" to close connection.\nftp2ouf> ");
}
