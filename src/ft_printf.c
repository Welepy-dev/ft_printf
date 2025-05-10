/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:39:13 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:57:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *main_string, ...)
{
	t_prt	prt;
	t_fmt	fmt;
	int		new_pos;

	init(&prt, main_string);
	va_start(prt.arg, main_string);
	while (main_string[prt.iterator])
	{
		if (main_string[prt.iterator] == '%')
		{
			ft_memset(&fmt, 0, sizeof(t_fmt));
			new_pos = parse_format(&prt, &fmt);
			if (new_pos != -1)
				start(&prt, &fmt, new_pos);
			else
				prt.len += ft_putchar(main_string[prt.iterator]);
		}
		else
			prt.len += ft_putchar(main_string[prt.iterator]);
		prt.iterator++;
	}
	va_end(prt.arg);
	ft_free(&prt.str);
	return (prt.len);
}
