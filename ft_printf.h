/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:19:26 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/19 19:35:11 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>

# define TRUE 1
# define FALSE 0

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
# define PER tools.per

# define FLAGS(c) (c == ' ' || c == '-' || c == '+' || c == '0' || c == '#')

# define FORMAT(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

typedef	struct	s_tools
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		prec;
	int		neg;
	char	type;
	int		per;
	int		width;
	int		precision;
	int		argument;
	int		form;
	int		len;
}				t_tools;

/*
** General use libft funcs
*/

int				ft_printf(const char *format, ...);
char			*ft_substr(int i, char *str);
char			*ft_strrev(char *str);
int				ft_findchar(char c, char *search);
void			ft_putwstr(wchar_t *str);

/*
** Parsing and solving funcs
*/

int				parse_format(char *format, t_tools tools, va_list ap);
int				parse_flag(char *format, t_tools tools, int *i, va_list ap);
int				find_flag(t_tools tools, va_list ap);

/*
** Conversion funcs
*/

int				convert_char(t_tools tools, va_list ap);
int				convert_int(t_tools tools, va_list ap);
int				convert_ptr(t_tools tools, va_list ap);
int				convert_ull(t_tools tools, va_list ap);
int				convert_wchar(t_tools tools, va_list ap, int ret);

/*
** Flag management funcs
*/

void			width(char *str, t_tools tools, char *arg);
char			*precision(t_tools tools, char *arg, int j);
void			hash(t_tools tools, char *str);
int				print_buffer(t_tools tools, va_list ap);

/*
** Extra tool funcs
*/

t_tools			reset_tools();
int				use_tools(t_tools tools, char *arg, int ret);
t_tools			assign_format(t_tools tools, char *format, int *i);
long long		use_format(t_tools tools, va_list ap);
__uint64_t		ull_use_format(t_tools tools, va_list ap);
t_tools			assign_flags(t_tools tools, char *format, int *i);

/*
** Number system conversions
*/

char			*ft_ulltoa(__uint64_t nbr);
char			*ft_itoabase(unsigned long long int nbr, t_tools tools,
						char *str, int base);
char			*ft_unitoa(wint_t wstr);

#endif
