/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:47 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 14:41:06 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_printf(char c, int base, t_fmt *fmt)
{
	const unsigned int	n = va_arg(fmt->args, unsigned int);
	const int			len = ft_unumlen(n, base);

	if (c == 'X')
		fmt->upper = 1;
	if (fmt->hashtag && n > 0)
		fmt->len += 2;
	if (fmt->precision > len)
		fmt->pad = fmt->precision - len;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	fmt->len += fmt->offset + fmt->pad + len;
	if (fmt->minus)
	{
		ft_putfnbr_base_fd(n, base, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, base, fmt, 1);
	}
}
