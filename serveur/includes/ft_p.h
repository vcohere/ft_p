/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:11:00 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/27 13:11:19 by vcohere          ###   ########.fr       */
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

// REMOVE ME
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
// PLEASE

void					treat_command(int sock, char *pwd);
void					ft_ls(int sock, char *str);
void					sig_handler(int signo);
void					get_file(int sock, char *name);
int						ft_strlenc(char *str, char c);
void					change_dir(char *path, char *pwd);
void					print_pwd(int sock, char *pwd);

#endif
