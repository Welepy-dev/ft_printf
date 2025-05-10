/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:09:43 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 14:10:12 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	hex_util(t_utility *utils, t_fmt *fmt, unsigned int n, char c)
{
	utils->index = 0;
	if (c == 'x')
		utils->hex.hex_digits = "0123456789abcdef";
	else
		utils->hex.hex_digits = "0123456789ABCDEF";
	if (n == 0 && fmt->precision_specified && fmt->precision == 0)
		utils->num_len = 0;
	else if (n == 0)
		utils->hex.hex_buffer[utils->index++] = '0';
	else
	{
		while (n > 0 && utils->index < 8)
		{
			utils->hex.hex_buffer[utils->index++]
				= utils->hex.hex_digits[n % 16];
			n /= 16;
		}
	}
}

void	print_hex(t_prt *prt, t_fmt *fmt, unsigned int n, char c)
{
	t_utility		utils;
	int				i;

	hex_util(&utils, fmt, n, c);
	utils.num_len = utils.index;
	utils.zeros = ternary((fmt->precision > utils.num_len),
			fmt->precision - utils.num_len, 0);
	utils.total_len = ternary((fmt->hash_flag && n != 0), 2, 0)
		+ utils.zeros + utils.num_len;
	utils.padding = ternary((fmt->width > utils.total_len),
			fmt->width - utils.total_len, 0);
	if (!fmt->left_justify && (!fmt->zero_padd || fmt->precision_specified))
		prt->len += ft_putnchar(' ', utils.padding);
	if (ternary((fmt->hash_flag && n != 0), 2, 0) == 2 && c == 'x')
		ft_putstr("0x");
	else if (ternary((fmt->hash_flag && n != 0), 2, 0) == 2 && c == 'X')
		ft_putstr("0X");
	if (!fmt->left_justify && fmt->zero_padd && !fmt->precision_specified)
		prt->len += ft_putnchar('0', utils.padding);
	prt->len += ft_putnchar('0', utils.zeros);
	i = utils.index;
	while (--i >= 0)
		prt->len += ft_putchar(utils.hex.hex_buffer[i]);
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', utils.padding);
}
