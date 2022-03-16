/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:23 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 21:31:30 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void				*ft_memset(void *dst, int value, size_t size);
void				ft_bzero(void *dst, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memccpy(void *dst, const void *src,
						int value, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t size);
void				*ft_memchr(const void *src, int value, size_t size);
int					ft_memcmp(const void *arr1, const void *arr2, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dst_len);
size_t				ft_strlcat(char *dst, const char *src, size_t dst_len);
char				*ft_strchr(const char *str, int value);
char				*ft_strrchr(const char *str, int value);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t size);
int					ft_strncmp(const char *str1, const char *str2, size_t size);
int					ft_atoi(const char *str);
int					ft_isalpha(int value);
int					ft_isdigit(int value);
int					ft_isalnum(int value);
int					ft_isascii(int value);
int					ft_isprint(int value);
int					ft_toupper(int value);
int					ft_tolower(int value);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
size_t				ft_strlen_sep(const char *str, int value);
int					ft_free_str(char **s);
void				*ft_free_str_arr(char ***arr);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strdup_sep(const char *s1, int value);

#endif
