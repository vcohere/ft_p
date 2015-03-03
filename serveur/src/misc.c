#include "ft_p.h"

int			ft_strlenc(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}