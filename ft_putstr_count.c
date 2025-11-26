/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:40:54 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(const char *s)
{
	int	len;

	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = 0;
	while (s[len])
	{
		if (write(1, &s[len], 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}
