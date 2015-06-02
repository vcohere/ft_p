/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:19:21 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/31 17:51:22 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				send_all(int sock, char *buf, int max)
{
	int					i;

	i = 0;
	while (i < max && (i = send(sock, buf, max, 0)) > 0)
		buf += i;
	ft_putnbr(i);
	ft_putendl("");
	//free(buf);
}

void					send_file(char *str, int sock)
{
	int					fd;
	struct stat			stat;
	char				*size;
	int					reat;
	char				buf[512];

	if (!str)
		return ;
	if ((fd = open(ft_strtrim(str), O_RDONLY)) == -1 || fstat(fd, &stat) == -1)
	{
		ft_putendl("File not found.");
		return ;
	}
	size = ft_itoa(stat.st_size);
	send_all(sock, size, ft_strlen(size));
	while ((reat = read(fd, buf, sizeof(buf))) > 0)
		send_all(sock, ft_strdup(buf), reat);
	close(fd);
}

void					get_file(int sock, char *name)
{
	int					r;
	char				buf[512];
	int					fd;
	int					size;
	int					res;

	r = read(sock, buf, sizeof(buf));
	buf[r] = '\0';
	size = ft_atoi(buf);
	ft_strclr(buf);
	r = 0;
	res = 0;
	fd = open(ft_strtrim(name), O_WRONLY | O_CREAT);
	while ((r = recv(sock, buf, sizeof(buf), 0)) > 0 && res < size)
	{
		write(fd, buf, r);
		res += r;
	}
	close(fd);
}
