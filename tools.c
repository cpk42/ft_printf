/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:44:31 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/21 17:11:06 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tools			reset_tools(void)
{
	t_tools	tools;

	PLUS = FALSE;
	MINUS = FALSE;
	ZERO = FALSE;
	SPACE = FALSE;
	HASH = FALSE;
	PREC = FALSE;
	NEG = FALSE;
	PER = FALSE;
	TYPE = FALSE;
	WIDTH = FALSE;
	PREC = FALSE;
	FORM = FALSE;
	LEN = FALSE;
	WIDE = FALSE;
	return (tools);
}

/*
** uses collected flags in tools struct to create final output string
*/

int				use_tools(t_tools tools, char *arg, int ret)
{
	char	str[9216];

	if (TYPE == '%' || (((TYPE == 'c' || TYPE == 'C') && !*arg)))
		ret += ft_specialbuffer(tools, arg);
	else
	{
		ft_bzero(str, 9216);
		if (TYPE == 'c' || TYPE == 'C')
			PREC = 0;
		if (PREC && ZERO)
			ZERO = FALSE;
		if (!WIDTH && !PREC)
			WIDTH = ft_strlen(arg);
		if (PREC > (int)ft_strlen(arg) && TYPE == 's')
			PREC = ft_strlen(arg);
		if (!PREC)
			PREC = ft_strlen(arg);
		arg = precision(tools, arg, 0);
		width(str, tools, arg);
		ft_putstr(str);
		ret += ft_strlen(str);
		ft_strdel(&arg);
	}
	return (ret);
}

/*
** Assigns format h hh l ll j z to t_tools
*/

t_tools			assign_format(t_tools tools, char *format, int *i)
{
	if (format[*i + 1] && format[*i] == 'h' && format[*i + 1] == 'h')
		FORM = 1;
	else if (format[*i] == 'h')
		FORM = 2;
	else if (format[*i + 1] && format[*i] == 'l' && format[*i + 1] == 'l')
		FORM = 4;
	else if (format[*i] == 'l')
		FORM = 3;
	else if (format[*i] == 'j')
		FORM = 5;
	else if (format[*i] == 'z')
		FORM = 6;
	while (FORMAT(format[*i]))
		(*i)++;
	return (tools);
}

/*
** returns arg as format type
*/

long long		use_format(t_tools tools, va_list ap)
{
	long long ret;

	if (!FORM)
		ret = va_arg(ap, int);
	else if (FORM == 1)
		ret = (char)va_arg(ap, int);
	else if (FORM == 2)
		ret = (short int)va_arg(ap, int);
	else if (FORM == 3)
		ret = va_arg(ap, long int);
	else if (FORM == 4)
		ret = va_arg(ap, long long int);
	else if (FORM == 5)
		ret = va_arg(ap, intmax_t);
	else if (FORM == 6)
		ret = va_arg(ap, size_t);
	else
		ret = 0;
	return (ret);
}

/*
** same as above but handles ull
*/

__uint64_t		ull_use_format(t_tools tools, va_list ap)
{
	__uint64_t ret;

	if (!FORM)
		ret = va_arg(ap, unsigned int);
	else if (FORM == 1)
		ret = (unsigned char)va_arg(ap, unsigned int);
	else if (FORM == 2)
		ret = (unsigned short int)va_arg(ap, unsigned int);
	else if (FORM == 3)
		ret = va_arg(ap, unsigned long int);
	else if (FORM == 4)
		ret = va_arg(ap, unsigned long long int);
	else if (FORM == 5)
		ret = va_arg(ap, uintmax_t);
	else if (FORM == 6)
		ret = va_arg(ap, size_t);
	else
		ret = 0;
	return (ret);
}
