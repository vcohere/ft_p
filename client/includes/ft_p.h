/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:11:00 by vcohere           #+#    #+#             */
/*   Updated: 2016/02/18 19:50:57 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include "../../libft/includes/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/stat.h>
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct stat		t_stat;

int						get_next_line(int fd, char **line);
void					sig_handler(int signo);
void					send_file(char *str, int sock);
void					get_file(int sock, char *name);
void					ft_putcolor(char *str, char *color);
void					usage(char *str);

#endif
