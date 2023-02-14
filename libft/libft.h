/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:32:42 by ngriveau          #+#    #+#             */
/*   Updated: 2023/02/13 19:27:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fcntl.h>
# include <bsd/string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_isalnum(int str);
int		ft_isalpha(int str);
int		ft_isascii(int str);
int		ft_isdigit(int str);
int		ft_isprint(int str);
char	*ft_itoa(int n);
void	*ft_memchr(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *str, char c);
char	*ft_strchr(char *str, int lettre);
char	*ft_strdup(char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(char *str, int lettre);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_strlen(char *str);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_tolower(int character);
int		ft_toupper( int character );
char	*ft_strnstr(char *src, char *cmp, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif