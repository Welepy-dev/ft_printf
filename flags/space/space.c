/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:00:16 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 13:24:57 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	space_helper(char **string, va_list args, t_printf *printf)
{
	printf->number = va_arg(args, long);
	if (printf->number >= 0)
		printf->length += ft_putchar(' ');
	printf->length += ft_putnbr(printf->number);
}
void	space(char **string, va_list args, t_printf *printf)
{
	(*string)++;
	if (**string == 'd' || **string == 'i')
		space_helper(string, args, printf);

}
