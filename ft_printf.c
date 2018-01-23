/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:48:08 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/22 21:16:46 by ckrommen         ###   ########.fr       */
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

void	find_flag(t_tools tools, char *str, va_list ap)
{
    if (TYPE == 's' || TYPE == 'c' || TYPE == '%')
		convert_char(tools, str, ap);
	else if (TYPE == 'd' || TYPE == 'i')
		convert_int(tools, str, ap);
	else if (TYPE == 'p' || TYPE == 'x' || TYPE == 'X' || TYPE == 'o' || TYPE == 'O')
		convert_ptr(tools, str, ap);
}

/*
** Handles every flag preceding the conversion character and assigns tools to it
*/

int		parse_flag(char *format, t_tools tools, char *str, int *i, va_list ap)
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
	find_flag(tools, str, ap);
	return (*i);
}

/*
** parses orignal format string until a % char is found
*/

int		parse_format(char *format, char *str, t_tools tools, va_list ap)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			str[j] = format[i];
			j++;
		}
		else
		{
			i = parse_flag(format, tools, str, &i, ap);
			tools = reset_tools();
			j = ft_strlen(str);
		}
		i++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	t_tools tools;
	char str[1024];
	va_list ap;
	
	va_start(ap, format);
	ft_bzero(str, 1024);
	tools = reset_tools();
	parse_format((char *)format, str, tools, ap);
	ft_putstr(str);
	va_end(ap);
	return (1);
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
