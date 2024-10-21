/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:09 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 17:04:50 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(t_fmt *fmt)
{
	int			len;
	const char	*str = va_arg(fmt->args, char *);

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - fmt->precision;
	fmt->len += fmt->offset + fmt->precision;
	if (fmt->minus)
	{
		ft_putnstr_fd((char *)str, fmt->precision, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putnstr_fd((char *)str, fmt->precision, 1);
	}
}
