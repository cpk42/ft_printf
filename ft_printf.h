/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:19:26 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/20 16:13:00 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS sSpdDioOuUxXcC

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define true 1
# define false 0

# define PLUS tools.plus
# define MINUS tools.minus
# define ZERO tools.zero
# define SPACE tools.space
# define HASH tools.hash
# define PREC tools.precision
# define STAR tools.star
# define TYPE tools.type
# define WIDTH tools.width
# define ARG tools.argument
# define RET tools.ret
# define LEN tools.len

/* Spacing Flags */
# define FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')

/* Conversion Flags */
# define CONV(c) (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
    c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'x' || c == 'X' || \
    c == 'c' || c == 'C')

/* Modifier Flags */
# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

typedef	struct s_tools
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		prec;
	int		star;
	char	type;
	int		width;
	int		precision;
	int		argument;
	int		ret;
	int		len;
}		t_tools;

int		ft_printf(const char *format, ...);
char	*ft_substr(int i, char *str);
char	*parse_flags(char *flag, va_list ap);
char	*parse_flags2(char *flag, va_list ap);
char	*ft_remalloc(char *str, int size);
int		parse_flag(char *format, char *str, t_tools tools, va_list ap, int *i);
int		parse_format(char *format, char *str, t_tools tools, va_list ap);
void	convert_char(t_tools tools, char *str, va_list ap);
void	convert_int(t_tools tools, char *str, va_list ap);
void	find_flag(t_tools tools, char *str, va_list ap);
t_tools	reset_tools();
void	use_tools(char *str, t_tools tools, char *arg);
void	width(char *str, t_tools tools, char *arg);

#endif
