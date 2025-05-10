/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:06:45 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/03 19:07:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	print_ptr(t_prt *prt, t_fmt *fmt)
{
	int					padding;
	unsigned long long	ptr;

	ptr = va_arg(prt->arg, unsigned long long);
	if (fmt->width > 1 && ptr != 0)
		padding = fmt->width - ft_ptr_len(ptr) - 2;
	else if (fmt->width > 1)
		padding = fmt->width - ft_strlen("(nil)");
	else
		padding = 0;
	if (!fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
	if (ptr == 0)
		prt->len += write(1, "(nil)", 5);
	else
	{
		prt->len += write(1, "0x", 2);
		ft_put_ptr(ptr);
		prt->len += ft_ptr_len(ptr);
	}
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', padding);
}
