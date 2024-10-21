/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:06:23 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 18:16:10 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putint_printf(t_fmt *fmt)
// {
// 	const int	n = va_arg(fmt->args, int);
// 	const int	len = ft_numlen(n, 10);
// 	const int	alen = ft_unumlen(ft_abs(n), 10);

// 	if (fmt->precision > alen)
// 		fmt->pad = fmt->precision - alen;
// 	if (fmt->zero && n < 0 && fmt->pad)
// 		--fmt->pad;
// 	if (fmt->width > fmt->pad + len)
// 		fmt->offset = fmt->width - fmt->pad - len;
// 	if ((fmt->space || fmt->plus) && n >= 0 && ++fmt->len && fmt->offset)
// 		--fmt->offset;
// 	fmt->len += fmt->offset + fmt->pad + len;
// 	if (fmt->minus)
// 	{
// 		ft_putfnbr_base_fd(n, 10, fmt, 1);
// 		while (fmt->offset--)
// 			ft_putchar_fd(' ', 1);
// 	}
// 	else
// 	{
// 		while (fmt->offset--)
// 			ft_putchar_fd(' ', 1);
// 		ft_putfnbr_base_fd(n, 10, fmt, 1);
// 	}
// }
// Функция для обработки случая, когда n == 0 и точность == 0

static int	ft_handle_zero_case(t_fmt *fmt, int n)
{
	if (n == 0 && fmt->dot && fmt->precision == 0)
	{
		if (fmt->width)
		{
			while (fmt->width--)
				ft_putchar_fd(' ', 1);
			fmt->len += fmt->width;
		}
		return (1);
	}
	return (0);
}

static void	ft_calculate_padding(t_fmt *fmt, int n, int len, int alen)
{
	if (fmt->precision > alen)
		fmt->pad = fmt->precision - alen;
	if (fmt->zero && n < 0 && fmt->pad)
		--fmt->pad;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	if ((fmt->space || fmt->plus) && n >= 0 && ++fmt->len && fmt->offset)
		--fmt->offset;
	fmt->len += fmt->offset + fmt->pad + len;
}

void	ft_putint_printf(t_fmt *fmt)
{
	const int	n = va_arg(fmt->args, int);
	const int	len = ft_numlen(n, 10);
	const int	alen = ft_unumlen(ft_abs(n), 10);

	if (ft_handle_zero_case(fmt, n))
		return ;
	ft_calculate_padding(fmt, n, len, alen);
	if (fmt->minus)
	{
		ft_putfnbr_base_fd(n, 10, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, 10, fmt, 1);
	}
}
