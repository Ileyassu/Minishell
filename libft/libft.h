/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:14 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/05/03 14:38:14 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

int					ft_isalpha(const int c);
char				*ft_strchr(const char *str, int c);
int					ft_isdigit(int arg);
int					ft_isalnum(const int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *ptr, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_atoi(const char *nbr);
int					ft_toupper(int c);
char				*ft_strrchr(const char *str, int c);
int					ft_tolower(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *str);
void				ft_bzero(void *ptr, size_t size);
void				*ft_calloc(size_t size, size_t count);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strncmp(const char *s1, const char *s2, size_t n);

t_list *ft_listnew(void *content);
void ft_listadd_front(t_list **list, t_list *new);
void ft_listadd_back(t_list **list, t_list *new);
void    ft_listdelone(t_list *list, void (*del)(void*));
int ft_listsize(t_list *list);
t_list *ft_listlast(t_list *list);
void ft_listclear(t_list **list, void (*del)(void*));

#endif
