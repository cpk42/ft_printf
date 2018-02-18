/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:48:08 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/12 14:05:59 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** argument prototype: %[flags][width/margin][.precision][hh|h|l|ll|j|z]type
**
** flags:			'+' || '-' || ' ' || '#' || '0';
**
** width/margin:	min amount of displayed digits, does not cut digits if less,
**					fill with spaces on the left side;
**					if '*' added it's necessary to pass one more parameter with
**					a number of spaces before the actual parameter;
**
** .precision:		for diouxX min amount of digits, fill with 0 is necessary;
**					for eEf amount of digits after dot;
**					for gG amount of all digits, if bigger displays number;
**					for sS max amount of characters;
**					if '*' added is necessary to pass one more parameter with a
**					number of spaces before the actual parameter;
**
** hh|h|l|ll|j|z|q:	default values' modification:
**						hh:	for idouxX - char;
**						h:	for idouxX - short int;
**						l:	for idouxX - long int, for feE - double;
**						ll:	for idouxX - long long int;
**						j:	for idouxX - intmax_t;
**						z:	for idouxX - size_t;
**						q:	for CS - prints Unicode
*/

/*
** Determines which conversion to be done with the given % arg
** sSpdDioOuUxXcC
**  %d %i     Decimal signed integer.
**  %o      Octal integer.
**  %x %X     Hex integer.
**  %u      Unsigned integer.
** %c      Character.
** %s      String.
** %c       char
** %p        pointer.
** No argument expected.
** % %%. No argument expected.
*/

int		find_flag(t_tools tools, va_list ap)
{
	int ret;

    if (TYPE == 's' || TYPE == 'c' || TYPE == '%')
		ret = convert_char(tools, ap);
	else if (TYPE == 'd' || TYPE == 'i')
		ret = convert_int(tools, ap);
	else if (TYPE == 'p' || TYPE == 'x' || TYPE == 'X' || TYPE == 'o' || TYPE == 'O')
		ret = convert_ptr(tools, ap);
	else if (TYPE == 'u' || TYPE == 'U')
		ret = convert_ull(tools, ap);
	else
		ret = 0;
	return (ret);
}

/*
** Handles every flag preceding the conversion character and assigns tools to it
*/

int		parse_flag(char *format, t_tools tools, int *i, va_list ap)
{
	while (!CONVERSIONS(format[*i]) && format[(*i)++])
	{
		if (FLAGS(format[*i]))
			tools = assign_flags(tools, format, i);
		else if (ft_isdigit(format[*i]))
			WIDTH = ft_atoi(ft_substr(*i, format));
		else if (format[*i] == '.')
			PREC = (format[*i + 1] && ft_isdigit(format[*i + 1])) ?
				ft_atoi(ft_substr(*i + 1, format)) : 0;
		else if (FORMAT(format[*i]))
			tools = assign_format(tools, format, i);
		else if (format[*i] == '%')
			break ;
		while ((ft_isdigit(format[*i + 1]) && format[*i + 1]) && (WIDTH || PREC))
			(*i)++;
	}
	TYPE = format[*i];
	return(find_flag(tools, ap));
}

/*
** parses orignal format string until a % char is found
*/

int		parse_format(char *format, t_tools tools, va_list ap)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			ret++;
		}
		else
		{
			ret += parse_flag(format, tools, &i, ap);
			tools = reset_tools();
		}
		i++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	t_tools tools;
	va_list ap;
	int		ret;

	va_start(ap, format);
	tools = reset_tools();
	ret = parse_format((char *)format, tools, ap);
	va_end(ap);
	tools = reset_tools();
//	while (1)
//		;
	return (ret);
}

/*
  sSpdDioOuUxXcC
  char 1 byte-128 to 127 or 0 to 255
  unsigned char 1 byte 0 to 255
  signed char 1 byte-128 to 127
  int2 or 4 bytes-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
  unsigned int2 or 4 bytes0 to 65,535 or 0 to 4,294,967,295
  short2 bytes-32,768 to 32,767
  unsigned short2 bytes0 to 65,535
  long4 bytes-2,147,483,648 to 2,147,483,647
  unsigned long4 bytes0 to 4,294,967,295
  float4 byte1.2E-38 to 3.4E+386 decimal places
  double8 byte2.3E-308 to 1.7E+30815 decimal places
  long double10 byte3.4E-4932 to 1.1E+493219 decimal places
  unsigned long long 18,446,744,073,709,551,615.
  \aaudible alert
  \bbackspace
  \fform feed
  \nnewline, or linefeed
  \rcarriage return
  \ttab
  \vvertical tab
  \						\backslash
  

  %d %i     Decimal signed integer.
  %o      Octal integer.
  %x %X     Hex integer.
  %u      Unsigned integer.
  %c      Character.
  %s      String. See below.
  %f      double
  %e %E     double.
  %g %G     double.
  %p        pointer.
  %n      Number of characters written by this printf.
  No argument expected.
  % %%. No argument expected.
*/
