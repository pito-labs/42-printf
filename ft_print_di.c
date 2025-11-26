/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:47:29 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_count('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	count += ft_putchar_count((char)('0' + (n % 10)));
	return (count);
}

int	ft_print_di(va_list ap)
{
	int		n;
	long	num;

	n = va_arg(ap, int);
	num = (long)n;
	return (ft_putnbr_count(num));
}
