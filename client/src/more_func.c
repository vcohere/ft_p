/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:07:24 by vcohere           #+#    #+#             */
/*   Updated: 2016/02/18 19:51:04 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\nUse \"exit\" to close connection.\n");
		ft_putcolor("ftp2ouf> ", "cyan");
	}
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

void				usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <address> <port>");
	exit(-1);
}
