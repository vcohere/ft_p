/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:11:00 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/30 13:43:55 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include "../../libft/includes/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/stat.h>

void					treat_command(int sock, char *pwd);
void					ft_ls(int sock, char *str);
void					sig_handler(int signo);
void					get_file(int sock, char *name);
void					send_file(char *str, int sock);
int						ft_strlenc(char *str, char c);
void					change_dir(char *path, char *pwd);
void					print_pwd(int sock, char *pwd);

#endif
