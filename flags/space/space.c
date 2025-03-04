/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:00:16 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 20:39:25 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include <unistd.h>

static int	padding(int allign, int num_len, char pad, bool positive)
{
	int	i;

	i = 0;
	while (i < allign - num_len - 1 - positive)
	{
		ft_putchar(pad);
		i++;
	}
	return (i);
}

static void	precision(char **string, t_printf *printf, int precision)
{
	(*string)++;
	if (printf->number < 0)
	{
		printf->length += ft_putchar('-');
		printf->number *= -1;
	}
	printf->length += padding(allign(string), num_len(printf->number) - precision, '0', 0);
}

void	space(char **string, va_list args, t_printf *printf)
{
	(*string)++;
	printf->number = va_arg(args, int);
	bool positive = (printf->number > 0);
	if (printf->number >= 0)
		printf->length += ft_putchar(' ');
	if (**string == '0')
		precision(string, printf, 0);
	else if (**string == '.')
		precision(string, printf, 1);
	else if (is_digit(**string))
		printf->length += padding(allign(string), num_len(printf->number) - 1, ' ', positive);
	printf->length += ft_putnbr(printf->number);	
	/*if (**string == '-')
		printf->length += padding(allign(string), num_len(printf->number) - 1, ' ', positive);*/
	//treat errors
}

/*
* space + -
* space + +
* space + #
* space + - + number
*/
