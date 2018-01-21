/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:48:08 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/20 16:26:56 by ckrommen         ###   ########.fr       */
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
** use the tools struct to deal with extra flags
*/
void	width(char *str, t_tools tools, char *arg)
{
	int i;
	int j;

	j = ft_strlen(str);
	i = WIDTH ? 0 : 1;
//	str[j++] = SPACE ? ' ' : 0;
	while (MINUS == false && WIDTH-- > (int)ft_strlen(arg))
		str[j++] = ZERO == true ? '0' : ' ';
	if (WIDTH == -1 && i)
		WIDTH = ft_strlen(arg);
	i = 0;
	while (arg[i] && WIDTH-- >= 0)
	{
		str[j] = arg[i];
		i++;
		j++;
	}
	while (MINUS == true && WIDTH-- > 0)
		str[j++] = ZERO == true ? '0' : ' ';
}

/*
** Determines which conversion to be done with the given % arg
*/
void	find_flag(t_tools tools, char *str, va_list ap)
{
    if (TYPE == 's' || TYPE == 'c')
		convert_char(tools, str, ap);
	else if (TYPE == 'd' || TYPE == 'i')
		convert_int(tools, str, ap);
}

/*
** Returns a pointer to the given index of a string
*/

char	*ft_substr(int i, char *str)
{
	while (i-- > 0)
		str++;
	return (str);
}

/*
** Handles every flag preceding the conversion character and assigns tools to it
*/

int		parse_flag(char *format, char *str, t_tools tools, va_list ap, int *i)
{
	while (!CONV(format[*i]) && format[*i])
	{
		PLUS = format[*i] == '+' ? true : false;
		MINUS = format[*i] == '-' ? true : false;
		ZERO = format[*i] == '0' ? true : false;
		if (format[*i] == '.')
		{
			if (ft_isdigit(format[++*i]))
			{
				PREC = ft_atoi(ft_substr(*i, format));
				while (ft_isdigit(format[*i + 1]) && format[*i + 1])
					(*i)++;
			}
		}
		else if (ft_isdigit(format[*i]))
		{
			WIDTH = ft_atoi(ft_substr(*i, format));
			while (ft_isdigit(format[*i + 1]) && format[*i + 1])
				(*i)++;
		}
		SPACE = (format[*i] == ' ' && !PLUS) ? true : false;
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
		if (format[i] != '%' && format[i])
		{
			str[j] = format[i];
			j++;
		}
		else
		{
			i = parse_flag(format, str, tools, ap, &i);
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

int		main()
{
//	ft_printf("asd");
//	printf("%d", 1);
	ft_printf("%9.7d\n", 1234);
	printf("%-9.7d\n", 1234);
//    ft_printf("%s%s\n", "string", "new");
//	printf("%s%s\n", "string", "new");
//	printf("%d", 'c');
    return 1;
}


/*
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
