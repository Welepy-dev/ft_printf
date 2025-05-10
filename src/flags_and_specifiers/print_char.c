/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:06:00 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:34:59 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	print_char(t_prt *prt, t_fmt *fmt)
{
	char	ch;
	int		padding;

	ch = (char)va_arg(prt->arg, int);
	padding = ternary((fmt->width > 1), fmt->width - 1, 0);
	if (!fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
	prt->len += ft_putchar(ch);
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
}
