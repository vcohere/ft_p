/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:19:21 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/03 04:19:22 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void				send_file(char *str, int sock)
{
	int				fd;
	struct stat		stat;
	char			*size;
	int				reat;
	char			buf[512];

	if (!str)
		return ;
	if ((fd = open(ft_strtrim(str), O_RDONLY)) == -1 || fstat(fd, &stat) == -1)
	{
		ft_putendl("File not found.");
		return ;
	}
	size = ft_itoa(stat.st_size);
	write(sock, size, ft_strlen(size));
	sleep(1);
	while ((reat = read(fd, buf, sizeof(buf))) > 0)
		send(sock, buf, reat, 0);
	close(fd);
}
