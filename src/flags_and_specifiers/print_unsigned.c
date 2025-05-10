/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:09:11 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:14:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	print_unsigned(t_prt *prt, t_fmt *fmt, unsigned int n)
{
	t_utility	utils;

	if (n == 0 && fmt->precision_specified && fmt->precision == 0)
		utils.num = ft_strdup("");
	else
		utils.num = ft_uitoa(n);
	utils.num_len = ft_strlen(utils.num);
	if (fmt->precision > utils.num_len)
		utils.zeros = fmt->precision - utils.num_len;
	else
		utils.zeros = 0;
	utils.total_len = utils.num_len + utils.zeros;
	if (fmt->width > utils.total_len)
		utils.padding = fmt->width - utils.total_len;
	else
		utils.padding = 0;
	if (!fmt->left_justify && (!fmt->zero_padd || fmt->precision_specified))
		prt->len += ft_putnchar(' ', utils.padding);
	else if (!fmt->left_justify && fmt->zero_padd && !fmt->precision_specified)
		prt->len += ft_putnchar('0', utils.padding);
	prt->len += ft_putnchar('0', utils.zeros);
	prt->len += ft_putstr(utils.num);
	if (fmt->left_justify)
		prt->len += ft_putnchar(' ', utils.padding);
	ft_free(&utils.num);
}
