/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:33:00 by vcohere           #+#    #+#             */
/*   Updated: 2015/06/02 13:43:05 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				send_all(int sock, char *buf, int max)
{
	int					i;

	i = 0;
	while ((i = send(sock, buf, max, 0)) > 0 && i < max)
		buf += i;
	free(buf);
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
	if ((fd = open(ft_strtrim(str), O_RDONLY | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1 || fstat(fd, &stat) == -1)
	{
		ft_putendl("File not found.");
		return ;
	}
	size = ft_itoa(stat.st_size);
	write(sock, size, ft_strlen(size));
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

	r = recv(sock, buf, sizeof(buf), 0);
	buf[r] = '\0';
	size = ft_atoi(buf);
	ft_bzero(buf, 512);
	r = 0;
	res = 0;
	fd = open(ft_strtrim(name), O_WRONLY | O_CREAT);
	while (res < size && (r = recv(sock, buf, sizeof(buf), 0)) > 0)
	{
		ft_putnbr(r);
		ft_putendl("");
		write(fd, buf, r);
		res += r;
	}
	ft_putnbr(res);
	ft_putendl("");
	close(fd);
}
