/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:28:52 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:32:56 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ternary(bool condition, int value, int option)
{
	if (condition)
		return (value);
	return (option);
}

void	handle_format(t_prt *prt, t_fmt *fmt)
{
	if (fmt->specifier == 'c')
		print_char(prt, fmt);
	else if (fmt->specifier == 's')
		print_str(prt, fmt);
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		print_integer(prt, fmt, va_arg(prt->arg, int));
	else if (fmt->specifier == 'p')
		print_ptr(prt, fmt);
	else if (fmt->specifier == 'u')
		print_unsigned(prt, fmt, va_arg(prt->arg, unsigned int));
	else if (fmt->specifier == 'X' || fmt->specifier == 'x')
		print_hex(prt, fmt, va_arg(prt->arg, unsigned int), fmt->specifier);
	else if (fmt->specifier == '%')
		prt->len += ft_putchar('%');
}
