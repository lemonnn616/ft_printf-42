/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:37:57 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 16:58:08 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fmt
{
	int		len;
	int		offset;
	int		pad;
	int		width;
	int		precision;
	int		hashtag;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	int		upper;
	va_list	args;
}	t_fmt;

void	ft_putchar_fd(char c, int fd);
void	ft_putchar_printf(t_fmt *fmt);
void	ft_putstr_printf(t_fmt *fmt);
void	ft_putptr_printf(t_fmt *fmt);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void	ft_putint_printf(t_fmt *fmt);
void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd);
void	ft_putuint_printf(char c, int base, t_fmt *fmt);
int		ft_unumlen(unsigned long long n, int base);
int		ft_numlen(int n, int base);
int		ft_abs(int i);
void	ft_putnstr_fd(char *s, int len, int fd);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);

#endif
