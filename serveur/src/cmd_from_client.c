/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_from_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:13:10 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/03 04:13:13 by vcohere          ###   ########.fr       */
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

void					treat_command(int sock)
{
	char				buf[1024];
	int					r;

	while ((r = read(sock, buf, sizeof(buf))) == 0)
		;
	buf[r] = '\0';
	if (ft_strnequ(buf, "pwd", 3))
	{
		getcwd(buf, sizeof(buf));
		write(sock, buf, ft_strlen(buf));
	}
	else if (ft_strnequ(buf, "ls", 2))
		ft_ls(sock, ft_strtrim(buf));
	else if (ft_strnequ(buf, "cd", 2))
		chdir(buf + 3);
	else
		write(sock, "Command not found.\n", 19);
	if (!(ft_strnequ(buf, "quit", 4)))
		treat_command(sock);
	ft_putendl("Goodbye user!");
	close(sock);
	exit(0);
}
