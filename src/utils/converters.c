/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:54:59 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/10 19:25:10 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*res;
	int				size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		nb = -((long)n);
	else
		nb = n;
	size = ft_num_len(nb);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (nb)
	{
		res[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n > 0)
	{
		num[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
