/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:07:24 by vcohere           #+#    #+#             */
/*   Updated: 2015/06/05 00:23:49 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\nUse \"exit\" to close connection.\nftp2ouf> ");
}

void					ft_putcolor(char *str, char *color)
{
	if (ft_strnequ(color, "red", 3))
		ft_putstr(ANSI_COLOR_RED);
	else if (ft_strnequ(color, "green", 5))
		ft_putstr(ANSI_COLOR_GREEN);
	else if (ft_strnequ(color, "blue", 4))
		ft_putstr(ANSI_COLOR_BLUE);
	else if (ft_strnequ(color, "yellow", 6))
		ft_putstr(ANSI_COLOR_YELLOW);
	else if (ft_strnequ(color, "cyan", 4))
		ft_putstr(ANSI_COLOR_CYAN);
	ft_putstr(str);
	ft_putstr(ANSI_COLOR_RESET);
}
