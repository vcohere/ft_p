/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:33:00 by vcohere           #+#    #+#             */
/*   Updated: 2016/02/17 18:26:03 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				send_all(int sock, char *buf, int max)
{
	int					i;

	i = 0;
	while (i < max && (i = send(sock, buf, max, 0)) > 0)
		buf += i;
}

void					send_file(char *str, int sock)
{
	int					fd;
	t_stat				stat;
	char				*size;
	int					reat;
	int					total_REMOVEME;
	char				buf[512];

	if (!str)
		return ;
	if ((fd = open(ft_strtrim(str), O_RDONLY)) == -1 || fstat(fd, &stat) == -1)
	{
		write(sock, "File not found.", 16);
		close(fd);
		return ;
	}
	total_REMOVEME = 0;
	size = ft_itoa(stat.st_size);
	send_all(sock, size, ft_strlen(size));
	while ((reat = read(fd, buf, sizeof(buf))) > 0)
	{
		total_REMOVEME += reat;
		send_all(sock, buf, reat);
		ft_putnbr(total_REMOVEME);
		ft_putstr("    ");
		ft_putnbr(reat);
		ft_putendl("");
	}
	ft_putendl("");
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
	if (ft_strequ("File not found.", buf))
		return ;
	size = ft_atoi(buf);
	ft_bzero(buf, 512);
	r = 0;
	res = 0;
	name = ft_strtrim(name);
	fd = open(name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	while (res < size && (r = recv(sock, buf, sizeof(buf), 0)) > 0)
	{
		write(fd, buf, r);
		res += r;
	}
	close(fd);
}
