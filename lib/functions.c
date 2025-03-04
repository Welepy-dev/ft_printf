/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:43:10 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 12:14:00 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void  *safe_malloc(size_t size)
{
	void  *ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2,"Malloc failed\n", 14);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

char  *ft_strdup(char *string)
{
	size_t	len;
	char  *dup;
	int	i;

	len = ft_strlen(string) + 1;
	dup = safe_malloc(len);
	i = -1;
	if (dup == NULL)
		return (NULL);
	while (string[++i])
		dup[i] = string[i];
	return (dup);
}
