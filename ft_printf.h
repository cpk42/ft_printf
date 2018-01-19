/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:19:26 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/03 17:59:34 by ckrommen         ###   ########.fr       */
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
# define PREC tools.prec
# define STAR tools.star
# define DISPLAY tools.display
# define TYPE tools.type
# define WIDTH tools.width
# define PRECISION tools.precision
# define ARGUMENT tools.argument
# define LEN tools.len

/* Spacing Flags */
# define FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')

/* Conversion Flags */
# define CONV(c) (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
    c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'x' || c == 'X' || \
    c == 'c' || c == 'C')

/* Modifier Flags */
# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'hh' || c == 'll')

typedef	struct s_tools
{
  int	plus;
  int	minus;
  int	zero;
  int	space;
  int	hash;
  int	prec;
  int	display;
  int	star;
  char	type;
  int	width;
  int	precision;
  int	argument;
  int	ret;
  int	len;
}		t_tools;


#endif
