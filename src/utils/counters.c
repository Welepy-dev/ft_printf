/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:41:51 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 13:05:44 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_num_len(long long num)
{
	int					len;
	unsigned long long	n;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		len++;
		n = -num;
	}
	else
		n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}
