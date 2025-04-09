/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:51:18 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/08 21:24:27 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//ALL THE C FILES
int		ft_atoi(const char *nptr); 	//OK
void	ft_bzero(void *s, size_t n);	//OK
void	*ft_calloc(size_t nmemb, size_t size);	//OK	
int		ft_isalnum(int c);	//OK
int		ft_isalpha(int c);	//OK
int		ft_isascii(int c);	//OK
int		ft_isdigit(int c);  //OK
int		ft_isprint(int c);  //OK
int		ft_tolower(int c);  //OK
int		ft_toupper(int c);	//OK
char	*ft_itoa(int n);	//OK
void	*ft_memchr(const void *s, int c, size_t n);	//OK
int		ft_memcmp(const void *s1, const void *s2, size_t n); //OK
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);	//OK
void	*ft_memmove(void *dest, const void *src, size_t n); //OK
void	*ft_memset(void *s, int c, size_t n); //OK
void	ft_putchar_fd(char c, int fd); //OK
void	ft_putendl_fd(char *s, int fd); //OK
void	ft_putnbr_fd(int n, int fd);	//
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	strlcat(char *restrict dst, const char *restrict src, size_t dsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
