#include "ft_p.h"

int			ft_strlenc(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

void		change_dir(char *path, char *pwd)
{
	char	buf[512];
	char	bof[512];

	getcwd(bof, sizeof(bof));
	chdir(path);
	getcwd(buf, sizeof(buf));
	if (!(ft_strnequ(buf, pwd, ft_strlen(pwd))))
		chdir(bof);
}

void		print_pwd(int sock, char *pwd)
{
	char	buf[512];
	int		len;
	int		offset;

	getcwd(buf, sizeof(buf));
	len = ft_strlen(pwd);
	offset = ft_strlen(buf) - len;
	if (ft_strequ(buf, pwd))
		write(sock, "/", 2);
	else
		write(sock, ft_strsub(buf, len, offset), offset);
}