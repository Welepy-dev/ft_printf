/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:40:45 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/10 19:22:51 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_prt
{
	int		iterator;
	int		len;
	char	*str;
	int		padding;
	va_list	arg;
}				t_prt;

typedef struct s_fmt
{
	int		left_justify;
	int		zero_padd;
	int		width;
	int		precision;
	int		precision_specified;
	int		plus_sign;
	int		space_sign;
	int		hash_flag;
	char	specifier;
}				t_fmt;

typedef struct s_hex
{
	char		*hex_digits;
	char		hex_buffer[9];
}				t_hex;

typedef struct s_utility
{
	int		num_len;
	int		zeros;
	int		padding;
	int		total_len;
	int		index;
	char	*num;
	int		prefix_len;
	t_hex	hex;
}				t_utility;

int		ft_printf(const char *main_string, ...);

//flags and specifiers
void	print_str(t_prt *prt, t_fmt *fmt);
void	print_ptr(t_prt *prt, t_fmt *fmt);
void	print_char(t_prt *prt, t_fmt *fmt);
int		parse_format(t_prt *prt, t_fmt *fmt);
void	handle_format(t_prt *prt, t_fmt *fmt);
void	print_integer(t_prt *prt, t_fmt *fmt, int n);
void	print_unsigned(t_prt *prt, t_fmt *fmt, unsigned int n);
void	print_hex(t_prt *prt, t_fmt *fmt, unsigned int n, char c);

//prints
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);
int		ft_putnchar(char c, int n);
int		ft_putnstr(char *str, int n);

//convertions
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_uitoa(unsigned int n);

//counters
int		ft_num_len(long long num);
int		ft_strlen(const char *s);
int		ft_ptr_len(uintptr_t num);

//string
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

//utils
void	init(t_prt *prt, const char *s);
int		ft_isdigit(int c);
void	ft_free(char **ptr);
void	*ft_memset(void *b, int c, size_t len);
void	start(t_prt *prt, t_fmt *fmt, int new_pos);
int		ternary(bool condition, int value, int option);

#endif
