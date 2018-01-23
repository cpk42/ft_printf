/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:44:31 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/22 21:08:56 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tools	reset_tools()
{
	t_tools tools;

	PLUS = false;
	MINUS = false;
	ZERO = false;
	SPACE = false;
	HASH = false;
	PREC = false;
	NEG = false;
	TYPE = 0;
	WIDTH = 0;
	PREC = 0;
	FORM = 0;
	LEN = 0;
	return (tools);
}

/*
** uses collected flags in tools struct to create final output string
*/
void	use_tools(char *str, t_tools tools, char *arg)
{
	if (WIDTH < PREC)
		WIDTH = PREC;
	if (ZERO && !PREC) //used for edgecase ("%+05d", -7) && ("%+05d", 7)
		PREC = WIDTH-1;
	if (TYPE != '%')
		arg = precision(tools, arg);
	width(str, tools, arg);
	if (PREC)
		ft_strdel(&arg);
}

/*
** Assigns format h hh l ll j z to t_tools
*/

t_tools	assign_format(t_tools tools, char *format, int *i)
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
		FORM = 7;
	while (FORMAT(format[*i]))
		(*i)++;
	return (tools);
}

/*
** Assigns flags to t_tools
*/

t_tools	assign_flags(t_tools tools, char *format, int *i)
{
	if (format[*i] == '+')
		PLUS = true;
	else if (format[*i] == '-')
		MINUS = true;
	else if (format[*i] == '0')
		ZERO = true;
	else if (format[*i] == ' ')
		SPACE = true;
	else if (format[*i] == '#')
		HASH = true;
	return (tools);
}
