/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:13 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/03 19:08:27 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	print_str(t_prt *prt, t_fmt *fmt)
{
	char	*str;
	int		padding;

	str = va_arg(prt->arg, char *);
	if (!str)
		str = "(null)";
	if (fmt->width > 1)
		padding = fmt->width - ft_strlen(str);
	else
		padding = 0;
	if (!fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
	if (fmt->precision_specified)
		prt->len += ft_putnstr(str, fmt->precision);
	else
		prt->len += ft_putstr(str);
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
}
