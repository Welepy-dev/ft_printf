/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:39:49 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:14:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	get_flags(t_prt *prt, t_fmt *fmt, int *i)
{
	while (ft_strchr("-0+# ", prt->str[*i]))
	{
		if (prt->str[*i] == '-')
			fmt->left_justify = 1;
		else if (prt->str[*i] == '0')
			fmt->zero_padd = 1;
		else if (prt->str[*i] == '+')
			fmt->plus_sign = 1;
		else if (prt->str[*i] == ' ')
			fmt->space_sign = 1;
		else if (prt->str[*i] == '#')
			fmt->hash_flag = 1;
		(*i)++;
	}
}

static void	get_width(t_prt *prt, t_fmt *fmt, int *i)
{
	fmt->width = ft_atoi(&prt->str[*i]);
	while (ft_isdigit(prt->str[*i]))
		(*i)++;
}

static void	get_precision(t_prt *prt, t_fmt *fmt, int *i)
{
	fmt->precision_specified = 1;
	(*i)++;
	fmt->precision = ft_atoi(&prt->str[*i]);
	while (ft_isdigit(prt->str[*i]))
		(*i)++;
}

int	parse_format(t_prt *prt, t_fmt *fmt)
{
	int	i;

	i = prt->iterator + 1;
	get_flags(prt, fmt, &i);
	if (ft_isdigit(prt->str[i]))
		get_width(prt, fmt, &i);
	if (prt->str[i] == '.')
		get_precision(prt, fmt, &i);
	if (ft_strchr("cspdiuxX%", prt->str[i]))
	{
		fmt->specifier = prt->str[i];
		return (i);
	}
	return (-1);
}
