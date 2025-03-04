/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:58:59 by welepy            #+#    #+#             */
/*   Updated: 2025/03/04 12:14:24 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_printf
{
	long  number;
	int	length;
} t_printf;


void  *safe_malloc(size_t size);
int	ft_strlen(char *string);
char  *ft_strdup(char *string);
int	ft_putchar(char c);
int	ft_printf(char *string, ...);
int	ft_putstr(char *string);

int	ft_num_len(unsigned int num);
int	ft_ptr_len(uintptr_t num);
size_t	num_len(int n);
int	ft_print_ptr(unsigned long long ptr);

int	ft_putstr(char *string);

int	ft_putnbr(long n);

char	*ft_uitoa(unsigned int n);

int	ft_print_unsigned(unsigned int n);

int	lower(unsigned int decimalnumber);

int	upper(unsigned int decimalnumber);
#endif
