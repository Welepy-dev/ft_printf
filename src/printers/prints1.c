/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:32:26 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:06:36 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i += 6;
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i += 6;
	}
	else
	{
		while (str[i] != '\0' && i < n)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	len++;
	return (len);
}
