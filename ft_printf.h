/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thirokaw <thirokaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:33:34 by thirokaw          #+#    #+#             */
/*   Updated: 2025/11/26 19:37:49 by thirokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define ERROR -1

int	ft_printf(const char *format, ...);

int	ft_putchar_count(char c);
int	ft_putstr_count(const char *s);
int	ft_print_cs(va_list ap, char spec);

int	ft_print_di(va_list ap);
int	ft_print_u(va_list ap);

int	ft_print_hex(va_list ap, char spec);
int	ft_print_ptr(va_list ap);

#endif
