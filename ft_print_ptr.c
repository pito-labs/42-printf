/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:19:12 by thirokaw          #+#    #+#             */
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

int	ft_print_ptr(va_list ap)
{
	unsigned long	ptr;
	int				count;

	ptr = (unsigned long)va_arg(ap, void *);
	if (ptr == 0)
		return (ft_putstr_count("(nil)"));
	count = ft_putstr_count("0x");
	count += ft_putnbr_base(ptr, "0123456789abcdef");
	return (count);
}
