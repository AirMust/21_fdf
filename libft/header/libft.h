/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:03:58 by slynell           #+#    #+#             */
/*   Updated: 2020/10/05 13:24:05 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "macros.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdint.h>
# include <wctype.h>

# define BUFF_SIZE_GNL 2
# define MAX_FD_COUNT 1025

/*
** Other function
*/
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(const wchar_t *s);
double				ft_pow(double base, register int_fast16_t power);
long double			ft_long_pow(long double base, register int_fast16_t power);
void				ft_assert(int_fast32_t to_check, const char *func,
					const char *message);
int32_t				ft_divmod(int32_t dividend, int32_t divisor,
					int32_t *remainder);
size_t				ft_intlen(register int32_t n);
void				ft_memswap(void *mem1, void *mem2, size_t size);
uint32_t			ft_abs(int32_t n);
size_t				ft_longlen(register int64_t n);
int					ft_strany(char const *str, int32_t c);
void				ft_strrev(register char *begin, register char *end);
size_t				ft_uitoa_hex(uint32_t value, char *buff,
					int_fast16_t is_upper);
size_t				ft_ultoa_hex(uint64_t value, char *buff,
					int_fast16_t is_upper);
size_t				ft_uitoa_dec(uint32_t val, char *buff);
size_t				ft_uitoa_base(uint32_t value, char *buff, int_fast16_t base,
					int_fast16_t is_upper);
size_t				ft_ultoa_base(uint64_t value, char *buff, int_fast16_t base,
					int_fast16_t is_upper);
int					get_next_line(const int fd, char **line);
long long			ft_atoill(const char *str);
int					ft_check_integer(char *str);
void				*ft_memset(void *in, int data, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t nb);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strmerge(char *a, char *b);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char*s, void (*f)(char *));
void				ft_striteri(char*s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str);
int					ft_countwords(char *str, char sep);
char				**ft_strsplit(char const *s, char c);
void				ft_strsplitfree(char ***strsplit);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_checkoverflow(int nbr, char *str);
int					ft_is_number(char *str);

/*
** String new function
*/
int					ft_str_ind(char *str, int c);

/*
** Array function
*/
void				ft_array_print(int *array, int length);
int					ft_array_max(int *array, int len);
int					ft_array_min(int *array, int len);
void				ft_free_matrix_char(char ***matrix, int count_row);
void				ft_free_matrix_int(int ***matrix, int count_row);
int					**ft_create_matrix_int(int count);
void				ft_print_matrix_int(int **matrix, int count);
void				ft_delete_table(int ***table, int rows);
int					**ft_do_table(int rows, int cols);
int					**ft_copy_matrix(int **src, int size);

/*
** List function
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstlink(t_list **alst, t_list *new);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstprint(t_list *alst);
void				ft_lstprint_fd(t_list *alst, int fd);
int					ft_lstaddcontent(t_list **alst, void *content, \
size_t content_size);
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstlink(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushback(t_list **alst, t_list *new);

/*
** QUEUE function
*/
typedef struct		s_queue
{
	void			*data;
	struct s_queue	*next;
}					t_queue;
void				ft_qpush(t_queue **head, void *data, size_t type_size);
void				*ft_qpop(t_queue **head, size_t type_size);
void				ft_qdel(t_queue **head);
#endif
