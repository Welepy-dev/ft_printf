/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:31:30 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 18:21:22 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  find_specifier(char **string, va_list args, t_printf *printf)
{
	if (**string == 'c')
		printf->length += ft_putchar(va_arg(args, int));
	else if (**string == 's')
		printf->length += ft_putstr(va_arg(args, char *));
	else if (**string == 'p')
		printf->length += ft_print_ptr(va_arg(args, unsigned long long int));
	else if (**string == 'd' || **string == 'i')
		printf->length += ft_putnbr(va_arg(args, long));
	else if (**string == 'u')
		printf->length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (**string == 'x')
		printf->length += lower(va_arg(args, unsigned int));
	else if (**string == 'X')
		printf->length += upper(va_arg(args, unsigned int));
	else if (**string == '%')
		printf->length += ft_putchar('%');
	else if (**string == ' ')
		space(string, args, printf);
	(*string)++;
}

int	ft_printf(char *string, ...)
{
	t_printf  *printf;
	va_list	args;
	int	i;

	printf = malloc(sizeof(t_printf *));
	printf->length = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			find_specifier(&string, args, printf);
		}
		else
		{
			printf->length += ft_putchar(*string);
			string++;
		}
	}
	i = printf->length;
	free(printf);
	return (i);
}
#include <stdio.h>
int	main(void)
{
	ft_printf("|% d|\n", 42);
	printf("|% d|\n", 42);
	ft_printf("|% 0d|\n", 42);
	printf("|% 0d|\n", 42);
	ft_printf("|% 05d|\n", 42);
	printf("|% 05d|\n", 42);
	ft_printf("|% 00000d|\n", 42);
	printf("|% 00000d|\n", 42);
	ft_printf("|% 5d|\n", 42);
	printf("|% 5d|\n", 42);
	ft_printf("|% .5d|\n", 42);  // " 00042"
	printf("|% .5d|\n", 42);  // " 00042"
	ft_printf("|% .3d|\n", 3); // " 3.140"
	printf("|% .3d|\n", 3); // " 3.140"
	ft_printf("|% 05d|\n", 42);  // " 00042"
	printf("|% 05d|\n", 42);  // " 00042"
	ft_printf("|% 03d|\n", 3); // " 3.140"
	printf("|% 03d|\n", 3); // " 3.140"
	ft_printf("|% -5d|\n", 42);  // " 42  "
	printf("|% -5d|\n", 42);  // " 42  "
	ft_printf("|% -10d|\n", 3); // " 3.14      "
	printf("|% -10d|\n", 3); // " 3.14      "

	return 0;
}
