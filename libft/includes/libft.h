/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:34:10 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/06 04:13:18 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# include <string.h>
# include "list.h"

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t len);
int				ft_isprint(int c);
int				ft_isalnum(int c);
size_t			ft_strlen(char const *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			*ft_memalloc(size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putendl(char const *str);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr(int number);
void			ft_putnbr_fd(int number, int fd);
void			ft_putstr(char const *str);
void			ft_putstr_fd(char const *str, int fd);
void			ft_strclr(char *str);
char			*ft_strcpy(char *dest, char const *src);
size_t			ft_strlcat(char *dest, char const *src, size_t size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_itoa(int number);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strdup(char const *str);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char const *src, size_t len);
int				ft_isspace(char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
char			*ft_strnstr(char const *s1, const char *s2, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
char			**ft_strsplit(char const *s, int c);
char			*ft_trimc(char const *str, char c);
int				ft_get_next_word_c(char const *s, char c);
char			*ft_strndup(char const *s, size_t len);
void			ft_strdel(char **as);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
int				ft_get_words_number_c(char const *str, char c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
int				ft_intlen(int number);
void			ft_putstrd(char *str, int number);
char			*ft_iformat(char *str, int number);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

#endif
