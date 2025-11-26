/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:36:02 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_count(va_list ap, char spec)
{
	int	add;

	add = 0;
	if (spec == 'c' || spec == 's')
		add = ft_print_cs(ap, spec);
	else if (spec == 'd' || spec == 'i')
		add = ft_print_di(ap);
	else if (spec == 'u')
		add = ft_print_u(ap);
	else if (spec == 'x' || spec == 'X')
		add = ft_print_hex(ap, spec);
	else if (spec == 'p')
		add = ft_print_ptr(ap);
	else if (spec == '%')
		add = ft_putchar_count('%');
	else if (spec == '\0')
		return (ERROR);
	else
		add = ft_putchar_count(spec);
	return (add);
}

int	ft_rp_check(va_list ap, const char *format)
{
	int	count;
	int	ret;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = add_count(ap, *format);
			if (ret == ERROR)
				return (ERROR);
			count += ret;
			format++;
			continue ;
		}
		else
		{
			if (write(1, format, 1) == ERROR)
				return (ERROR);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_rp_check(ap, format);
	if (ret == ERROR)
	{
		va_end(ap);
		return (ERROR);
	}
	va_end(ap);
	return (ret);
}
