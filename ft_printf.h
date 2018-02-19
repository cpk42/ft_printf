/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:19:26 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/18 14:22:49 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

# define true 1
# define false 0

# define LL_MAX 9223372036854775807
# define LL_MIN -9223372036854775807 - 1

# define INT_MAX 2147483647
# define INT_MIN 2147483648

# define PLUS tools.plus
# define MINUS tools.minus
# define ZERO tools.zero
# define SPACE tools.space
# define HASH tools.hash
# define PREC tools.precision
# define TYPE tools.type
# define WIDTH tools.width
# define FORM tools.form
# define LEN tools.len
# define NEG tools.neg

# define FLAGS(c) (c == ' ' || c == '-' || c == '+' || c == '0' || c == '#')

# define CONVERSIONS(c) (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
    c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || \
    c == 'c' || c == 'C')

# define FORMAT(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

# define ZPAD(c) (c == 'i' || c == 'u' || c == 'd' || c == 'x' || c == 'X' || c == 'o' || c == 'O')

typedef	struct s_tools
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		prec;
	int		neg;
	char	type;
	int		width;
	int		precision;
	int		argument;
	int		form;
	int		len;
}		t_tools;

/*
** General use libft funcs
*/

int		ft_printf(const char *format, ...);
char	*ft_substr(int i, char *str);
char	*ft_strrev(char *str);

/*
** Parsing and solving funcs
*/

int		parse_format(char *format, t_tools tools, va_list ap);
int		parse_flag(char *format, t_tools tools, int *i, va_list ap);
int		find_flag(t_tools tools, va_list ap);

/*
** Conversion funcs
*/

int		convert_char(t_tools tools, va_list ap);
int		convert_int(t_tools tools, va_list ap);
int		convert_ptr(t_tools tools, va_list ap);
int		convert_ull(t_tools tools, va_list ap);
int		convert_wchar(t_tools tools, va_list ap);

/*
** Flag management funcs
*/

void		width(char *str, t_tools tools, char *arg);
char		*precision(t_tools tools, char *arg, int j);
void		hash(t_tools tools, char *str);

/*
** Extra tool funcs
*/

t_tools		reset_tools();
int			use_tools(t_tools tools, char *arg);
t_tools		assign_format(t_tools tools, char *format, int *i);
long long	use_format(t_tools tools, va_list ap);
__uint64_t	ull_use_format(t_tools tools, va_list ap);
t_tools		assign_flags(t_tools tools, char *format, int *i);

/*
** Number system conversions
*/

char	*ft_ulltoa(__uint64_t nbr);
char	*ft_itoh(unsigned long long int nbr, t_tools tools, char *str);
char	*ft_itoo(unsigned long long int nbr, t_tools tools, char *str);

#endif
