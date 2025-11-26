/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:46:29 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_base(char c)
{
	return (ft_putchar_count(c));
}

static int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_base(n / 16, base);
	count += ft_putchar_base(base[n % 16]);
	return (count);
}

int	ft_print_hex(va_list ap, char spec)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (spec == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
}
