/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:46 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/06 12:48:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	init(t_prt *prt, const char *s)
{
	prt->iterator = 0;
	prt->len = 0;
	prt->str = ft_strdup(s);
}

void	ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

void	start(t_prt *prt, t_fmt *fmt, int new_pos)
{
	handle_format(prt, fmt);
	prt->iterator = new_pos;
}
