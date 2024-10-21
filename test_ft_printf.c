/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:22:38 by iriadyns          #+#    #+#             */
/*   Updated: 2024/10/21 18:19:57 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	x;

	x = 42;
	printf("Standard printf: '%7.3d' '%.0i'\n", 42, 0);
	ft_printf("Custom ft_printf: '%7.3d' '%.0i'\n", 42, 0);
	printf("Standard printf: %#x %X\n", 2829, 2550);
	ft_printf("Custom ft_printf: %x %X\n", 2550, 2550);
	printf("Standard printf: %u\n", 4294967295u);
	ft_printf("Custom ft_printf: %u\n", 4294967295u);
	printf("Standard printf: '%s'\n", "wfwffw");
	ft_printf("Custom ft_printf: '%s'\n", "gwgwgw");
	printf("Standard printf: %%\n");
	ft_printf("Custom ft_printf: %%\n");
	printf("Standard printf: %p %p\n", (void *)&x, (void *)0);
	ft_printf("Custom ft_printf: %p %p\n", (void *)&x, (void *)0);
	return (0);
}
