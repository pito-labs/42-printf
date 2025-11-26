/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:06 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_cs(va_list ap, char spec)
{
	if (spec == 'c')
		return (ft_putchar_count(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr_count(va_arg(ap, char *)));
	return (0);
}
