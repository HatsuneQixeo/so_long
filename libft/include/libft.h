/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:08:16 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/05 15:08:17 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef char	*(*t_ftstr)(const char *str1, const char *str2);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	**ft_file_extract_lst(const char *file);
char	**ft_file_extract_split(const char *file);
char	*ft_file_extract(int fd);
int		ft_file_format(const char *file, const char *format);
int		ft_file_open(const char *file);

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_within(int min, int nbr, int max);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(char c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(char c);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*ft)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*ft)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstselect(t_list *lst, size_t select);
int		ft_lstsize(t_list *lst);

int		ft_putchar_fd(const char c, int fd);
int		ft_putendl_fd(const char *str, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putstrlist_fd(char **strlist, int fd);
int		ft_strrelease_fd(char *str, int fd);

void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t len, size_t size);
void	*ft_memchr(const void *str, int c, size_t bytes);
int		ft_memcmp(const void *str1, const void *str2, size_t bytes);
void	*ft_memcpy(void *dst, const void *src, size_t bytes);
void	*ft_memmove(void *dst, const void *src, size_t bytes);
void	*ft_memset(void *str, int c, size_t bytes);
void	ft_memswap(void *ptr1, void *ptr2, size_t bytes);
char	**ft_split(const char *str, char c);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcombine(char *str1, char *str2);
char	*ft_strdup(const char *str1);
void	ft_striteri(char *str, void (*ft)(unsigned int, char *));
char	*ft_strrjoin(const char *str, const char *add);
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char *str, char (*ft)(unsigned int, char));
char	*ft_strmodify(char *str, const char *mod, t_ftstr ft_str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strtrim(const char *src, const char *set);
char	*ft_substr(const char *str, unsigned int home, size_t len);

void	ft_clear_strlist(char **strlist);
int		ft_strcount(char **strlist);
char	*ft_strlistchr(char **strlist, char c);
char	**ft_strlistdup(char **strlist);
char	*ft_strliststr(char **strlist, const char *str);

void	ft_swapchar(char *sign, char *set);
char	*ft_strskipchr(char *str, char c);
char	*ft_strcreate(char set, size_t size);
char	*ft_strfill(char *str, char set, int len_add, t_ftstr ft_str);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa_base(uintptr_t un_n, const char *base);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	ft_mapi_capitalize(unsigned int i, char c);
char	ft_mapi_lower(unsigned int i, char c);
char	ft_mapi_miku(unsigned int i, char c);
char	ft_mapi_upper(unsigned int i, char c);

void	ft_iteri_lower(unsigned int i, char *str);
void	ft_iteri_upper(unsigned int i, char *str);

#endif
