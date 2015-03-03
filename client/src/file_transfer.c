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
	int				sent;
	char			buf[512];

	if ((fd = open(ft_strtrim(str), O_RDONLY)) == -1 || fstat(fd, &stat) == -1)
	{
		printf("File not found: %s", ft_strtrim(str));
		return ;
	}
	size = ft_strjoin("put", ft_itoa(stat.st_size));
	sent = 0;
	write(sock, size, ft_strlen(size));
	while ((sent += send(sock, buf, sizeof(buf), MSG_OOB)) < stat.st_size)
		read(fd, buf, sizeof(buf));
}

void				get_file(int sock)
{
	int				r;
	int				size;
	char			buf[1024];

	while ((r = read(sock, buf, sizeof(buf))) == 0)
		;
	buf[r] = '\0';
	size = ft_atoi(buf + 3);
	ft_putnbr(size);
}
