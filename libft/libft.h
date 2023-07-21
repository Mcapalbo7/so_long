/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:41 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/06/22 22:11:36 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char				*get_next_line(int fd);
int					ft_putstr(char *s);
void				*ft_memset(void *dest, int val, size_t count);
void				ft_bzero(void *dest, size_t l);
void				*ft_memcpy(void *dest, const void *src, size_t c);
void				*ft_memmove(void *dest, const void *src, size_t c);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t s);
char				*ft_strchr(const char *str, int count);
char				*ft_strrchr(const char *str, int count);
char				*ft_strnstr(const char *str, const char *to_find, \
					size_t len);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int a);
int					ft_isdigit(int a);
int					ft_isalnum(int a);
int					ft_isascii(int a);
int					ft_isprint(int c);
int					ft_toupper(int count);
int					ft_tolower(int count);
void				*ft_calloc(size_t nmem, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
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
void				ft_lstadd_front(t_list **lista, t_list *new);
int					ft_lstsize(t_list *lista);
t_list				*ft_lstlast(t_list *lista);
void				ft_lstadd_back(t_list **list, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
#endif
