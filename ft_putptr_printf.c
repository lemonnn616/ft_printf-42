/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:07:18 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 18:05:29 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	ft_putptr_null(t_fmt *fmt)
{
	ft_putstr_fd("(nil)", 1);
	fmt->len += 5;
}

static void	ft_putptr_value(unsigned long long ptr, t_fmt *fmt)
{
	ft_putstr_fd("0x", 1);
	ft_putunbr_base_fd(ptr, 16, 1);
	fmt->len += ft_unumlen(ptr, 16) + 2;
}

void	ft_putptr_printf(t_fmt *fmt)
{
	unsigned long long	ptr;
	int					len;

	ptr = (unsigned long long)va_arg(fmt->args, void *);
	if (ptr == 0)
		return (ft_putptr_null(fmt));
	len = ft_unumlen(ptr, 16) + 2;
	if (fmt->width > len)
		fmt->offset = fmt->width - len;
	else
		fmt->offset = 0;
	if (fmt->minus)
	{
		ft_putptr_value(ptr, fmt);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putptr_value(ptr, fmt);
	}
}
