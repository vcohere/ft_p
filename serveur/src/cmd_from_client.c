/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_from_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:13:10 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/30 16:25:42 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					sig_handler(int signo)
{
	if (signo == SIGCHLD)
		wait4(-1, NULL, WNOHANG, NULL);
}

void					ft_ls(int sock, char *str)
{
	DIR					*dir;
	struct dirent		*file;
	char				**split;
	char				*res;

	split = ft_strsplit(str, ' ');
	res = ft_strdup("");
	if (split[1])
		dir = opendir(ft_strtrim(split[1]));
	else
		dir = opendir(".");
	while ((file = readdir(dir)) != NULL)
		res = ft_strjoin(ft_strjoin(res, file->d_name), "\n");
	res[ft_strlen(res) - 1] = '\0';
	write(sock, res, ft_strlen(res));
	closedir(dir);
}

void					treat_command(int sock, char *pwd)
{
	char				buf[1024];
	int					r;

	while ((r = read(sock, buf, sizeof(buf))) == 0)
		;
	buf[r] = '\0';
	if (ft_strnequ(buf, "pwd", 3))
		print_pwd(sock, pwd);
	else if (ft_strnequ(buf, "put", 3))
		get_file(sock, buf + 4);
	else if (ft_strnequ(buf, "ls", 2))
		ft_ls(sock, ft_strtrim(buf));
	else if (ft_strnequ(buf, "cd", 2))
		change_dir(buf + 3, pwd);
	else if (ft_strnequ(buf, "get", 3))
		send_file(buf + 4, sock);
	else
		write(sock, "Command not found.\n", 19);
	if (!(ft_strnequ(buf, "quit", 4)))
		treat_command(sock, pwd);
	ft_putendl("User disconnected.");
	close(sock);
}
