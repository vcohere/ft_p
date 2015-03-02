#include "ft_p.h"

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
}

void					treat_command(int sock)
{
	char				buf[1024];
	int					r;

	while (1)
	{
		if ((r = read(sock, buf, sizeof(buf))) > 0)
		{
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
		}
	}
}