/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:10:40 by vcohere           #+#    #+#             */
/*   Updated: 2015/06/05 00:01:45 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <port>");
	exit(-1);
}

static int				create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Bind error. Just wait a minute or change port.");
		exit(2);
	}
	listen(sock, 10);
	return (sock);
}

static void				stay_connected(int sock)
{
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				pid;
	char				buf[512];

	signal(SIGCHLD, sig_handler);
	getcwd(buf, sizeof(buf));
	while (1)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		ft_putendl("New user connected.");
		if ((pid = fork()) < 0)
		{
			write(cs, "Fork error. Closing connection.\n", 32);
			close(cs);
		}
		else if (pid > 0)
			close(cs);
		else if (pid == 0)
			treat_command(cs, ft_strdup(buf));
	}
	close(sock);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	stay_connected(sock);
	return (0);
}
