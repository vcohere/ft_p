/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:10:40 by vcohere           #+#    #+#             */
/*   Updated: 2015/06/05 00:17:37 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <address> <port>");
	exit(-1);
}

static int				create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		return (-1);
	if (ft_strequ(addr, "localhost"))
		addr = ft_strdup("127.0.0.1");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Connection error. Maybe you should start the server?");
		exit(-1);
	}
	return (sock);
}

static void				wait_response(int sock, char *str)
{
	int					r;
	char				buf[1024];

	while ((r = read(sock, buf, sizeof(buf))) == 0)
		;
	buf[r] = '\0';
	if (ft_strnequ(str, "ls", 2))
		ft_putstr(buf);
	else
		ft_putendl(buf);
}

static void				treat_command(char *str, int sock)
{
	if (ft_strnequ(str, "ls", 2) || ft_strnequ(str, "pwd", 3) ||
		ft_strnequ(str, "get ", 4) || ft_strnequ(str, "exit", 4) ||
		ft_strnequ(str, "put ", 4) || ft_strnequ(str, "cd ", 3))
		write(sock, str, ft_strlen(str));
	else if (ft_strnequ(str, "quit", 4))
		write(sock, "exit", 4);
	else
	{
		ft_putendl("Command not found.");
		return ;
	}
	if (ft_strnequ(str, "exit", 4) || ft_strnequ(str, "quit", 4))
	{
		ft_putendl("Goodbye!");
		exit(0);
	}
	if (ft_strnequ(str, "put ", 4))
		send_file(str + 4, sock);
	else if (ft_strnequ(str, "get ", 4))
		get_file(sock, ft_strtrim(str + 4));
	else if (!(ft_strnequ(str, "cd ", 3)))
		wait_response(sock, str);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	char				*line;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putcolor("ftp2ouf> ", "cyan");
	signal(SIGINT, sig_handler);
	while (get_next_line(0, &line) > 0)
	{
		treat_command(line, sock);
		ft_putcolor("ftp2ouf> ", "cyan");
	}
	close(sock);
	return (0);
}
