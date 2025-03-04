/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:50:22 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 14:52:49 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdbool.h>

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

bool  is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	allign(char **string)
{
	int	allign;

	allign = 0;
	while(is_digit(**string))
	{
		allign = allign * 10 + (**(string) - '0');
		(*string)++;
	}
	return (allign);
}
