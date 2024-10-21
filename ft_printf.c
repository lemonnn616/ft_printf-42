/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:03:17 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 16:58:07 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_reset(t_fmt *fmt)
{
	fmt->offset = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->hashtag = 0;
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->dot = 0;
	fmt->upper = 0;
}

static void	pf_subprocess(char c, t_fmt *fmt)
{
	if (c >= '0' && c <= '9')
	{
		if (fmt->dot || fmt->zero)
			fmt->precision = fmt->precision * 10 + c - '0';
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = 1;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		fmt->hashtag = 1;
	else if (c == '-')
		fmt->minus = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == '.')
		fmt->dot = 1;
}

static char	*pf_process(char *str, t_fmt *fmt)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
		pf_subprocess(*str++, fmt);
	if (*str == 'c')
		ft_putchar_printf(fmt);
	else if (*str == 's')
		ft_putstr_printf(fmt);
	else if (*str == 'p')
		ft_putptr_printf(fmt);
	else if (*str == 'd' || *str == 'i')
		ft_putint_printf(fmt);
	else if (*str == 'u')
		ft_putuint_printf(*str, 10, fmt);
	else if (*str == 'x' || *str == 'X')
		ft_putuint_printf(*str, 16, fmt);
	else if (*str == '%' && ++fmt->len)
		ft_putchar_fd(*str, 1);
	return (++str);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	t_fmt	fmt;

	ret = 0;
	fmt.len = 0;
	init_reset(&fmt);
	va_start(fmt.args, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str = pf_process((char *)str, &fmt);
			init_reset(&fmt);
		}
		else if (++ret)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt.args);
	ret += fmt.len;
	return (ret);
}
