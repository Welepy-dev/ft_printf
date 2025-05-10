/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:43 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/10 19:24:38 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	print_flags(t_prt *prt, t_fmt *fmt, t_utility *utils, int n)
{
	if (!fmt->left_justify && (!fmt->zero_padd || fmt->precision_specified))
		prt->len += ft_putnchar(' ', utils->padding);
	if (n < 0)
		prt->len += write(1, "-", 1);
	else if (fmt->plus_sign)
		prt->len += write(1, "+", 1);
	else if (fmt->space_sign)
		prt->len += write(1, " ", 1);
	if (!fmt->left_justify && fmt->zero_padd && !fmt->precision_specified)
		prt->len += ft_putnchar('0', utils->padding);
	prt->len += ft_putnchar('0', utils->zeros);
}

void	print_integer(t_prt *prt, t_fmt *fmt, int n)
{
	t_utility	utils;
	int			is_negative;
	int			has_sign;

	is_negative = (n < 0);
	has_sign = (is_negative || fmt->plus_sign || fmt->space_sign);
	if (n == 0 && fmt->precision_specified && fmt->precision == 0)
		utils.num = ft_strdup("");
	else
		utils.num = ft_itoa(n);
	utils.num_len = ft_strlen(utils.num) - is_negative;
	utils.zeros = ternary((fmt->precision > utils.num_len),
			fmt->precision - utils.num_len, 0);
	utils.total_len = utils.num_len + utils.zeros + has_sign;
	utils.padding = ternary((fmt->width > utils.total_len),
			fmt->width - utils.total_len, 0);
	utils.padding -= is_negative;
	utils.zeros -= is_negative;
	print_flags(prt, fmt, &utils, n);
	prt->len += ft_putstr(utils.num);
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', utils.padding);
	ft_free(&utils.num);
}
