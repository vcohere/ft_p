/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_from_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:13:10 by vcohere           #+#    #+#             */
/*   Updated: 2015/06/04 01:46:46 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					sig_handler(int signo)
{
	if (signo == SIGCHLD)
		wait4(-1, NULL, 0, NULL);
}

void					ft_ls(int sock, char *str, char **env)
{
	char				**split;
	pid_t				pid;

	split = ft_strsplit(str, ' ');
	if ((pid = fork()) < 0)
	{
		write(sock, "Fork error. Closing connection.\n", 32);
		close(sock);
	}
	else if (pid == 0)
	{
		dup2(sock, 1);
		dup2(sock, 2);
		execve("/bin/ls", split, env);
	}
}

void					treat_command(int sock, char *pwd, char **env)
{
	char				buf[1024];
	int					r;

	r = read(sock, buf, sizeof(buf));
	buf[r] = '\0';
	if (ft_strnequ(buf, "pwd", 3))
		print_pwd(sock, pwd);
	else if (ft_strnequ(buf, "put", 3))
		get_file(sock, buf + 4);
	else if (ft_strnequ(buf, "ls", 2))
		ft_ls(sock, ft_strtrim(buf), env);
	else if (ft_strnequ(buf, "cd", 2))
		change_dir(buf + 3, pwd);
	else if (ft_strnequ(buf, "get", 3))
		send_file(buf + 4, sock);
	else
		write(sock, "Command not found.\n", 19);
	if (!(ft_strnequ(buf, "exit", 4)))
		treat_command(sock, pwd, env);
	ft_putendl("User disconnected.");
	exit(0);
	close(sock);
}
