/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:30:54 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/03 19:37:12 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_remalloc(char *str, int size)
{
	char *new;

	if (str)
	{
		new = ft_strnew(ft_strlen(str) + size);
		ft_memset((void *)new, '.', ft_strlen(str) + (size - 1));
		new = ft_strcpy(new, str);
		ft_strdel(&str);
		return (new);
	}
	return (NULL);
}

char	*parse_flags2(char *flag, va_list ap)
{
	if (*flag == 'u')
		return ("UNSIGNED_INT");
	else if (*flag == 'U')
		return ("UNSIGNED_INT");
	else if (*flag == 'x')
		return (ft_itoa(va_arg(ap, int)));
	else if (*flag == 'X')
		return (ft_itoa(va_arg(ap, int)));
	else if (*flag == 'c')
		return (va_arg(ap, char *));
	else if (*flag == 'C')
		return ("BROKEN");
	else
		return ("END");
}


char	*parse_flags(char *flag, va_list ap)
{
	if (*flag == 's')
		return (va_arg(ap, char *));
	else if (*flag == 'S')
		return ("BIG OL STRING");
	else if (*flag == 'p')
		return (va_arg(ap, char *));
	else if (*flag == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (*flag == 'D')
		return ("LONG_INT");
	else if (*flag == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (*flag == 'o')
		return (ft_itoa(va_arg(ap, int)));
	else if (*flag == 'O')
		return ("LONG_INT");
	else
		return (parse_flags2(flag, ap));
}

t_flag	*create_elem(char *flag)
{
	t_flag	*new;

	new = (t_flag *)malloc(sizeof(t_flag));
	new->flag = flag;
	new->next = NULL;
	return (new);
}

t_flag	*add_link(t_flag *head, t_flag *new)
{
	t_flag	*ptr;

	ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	ptr = ptr->next;
	ptr->next = NULL;
	return (head);
}

t_flag	*parse_format(char *format, t_flag *head)
{
	int		i;
	int		cur;
	char	*flag;

	i = 0;
	cur = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			i++;
		if (format[i] == '%' && i != 0)
		{
			flag = ft_strsub(format, cur, (i - cur));
			head = add_link(head, create_elem(flag));
			cur = i;
			i++;
		}
		else
			i++;
	}
	if (*format)
		head = add_link(head, create_elem(ft_strsub(format, cur, (i - cur))));
	return (head);
}

t_flag	*parse_list(t_flag *head, va_list ap)
{
	t_flag	*ptr;
	int i;

	i = 0;
	ptr = head;
	ptr = ptr->next;
	va_arg(ap, void *);
/*	while (ptr)
	{
		if (*ptr->flag == '%')
			ptr->ap = parse_flags(ptr, ap);
		
			}*/
	return (head);
}

int main(void)
{
	char *str;
	
	str = ft_strnew(7);
	str = "string\0";
	printf("%hhs", str);
	return 0;
}

/*
char	1 byte	-128 to 127 or 0 to 255
unsigned char	1 byte	0 to 255
signed char	1 byte	-128 to 127
int	2 or 4 bytes	-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
unsigned int	2 or 4 bytes	0 to 65,535 or 0 to 4,294,967,295
short	2 bytes	-32,768 to 32,767
unsigned short	2 bytes	0 to 65,535
long	4 bytes	-2,147,483,648 to 2,147,483,647
unsigned long	4 bytes	0 to 4,294,967,295
float	4 byte	1.2E-38 to 3.4E+38	6 decimal places
double	8 byte	2.3E-308 to 1.7E+308	15 decimal places
long double	10 byte	3.4E-4932 to 1.1E+4932	19 decimal places
unsigned long long 18,446,744,073,709,551,615.
\a	audible alert
\b	backspace
\f	form feed
\n	newline, or linefeed
\r	carriage return
\t	tab
\v	vertical tab
\\	backslash


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
/*
char	*parse_format(char *format, char *res, va_list ap)
{
	int i;

	i = 0;
	while (*format)
	{
		if (ft_isalpha(*format) || *format == 32)
		{
			if (!res)
				res = ft_strnew(1);
			else if (!res[i])
				res = ft_remalloc(res);
			res[i] = *format;
			i++;
		}
		else if (*format == '%')
		{
			format++;
			if (!res)
			  res = parse_flags(format, ap);
			else
			  res = ft_strjoin(res, parse_flags(format, ap));
			i = ft_strlen(res);
		}
		format++;
	}
	return (res);
}

	if ((mem = ft_strchr(format, '%')))
	{
		*mem = '\0';
		flag = ft_strdup(format);
		format = ft_strdup(mem + 1);
		head = add_link(head, create_elem(flag));
		parse_format(format, ap, head);
	}
	else
	{
		flag = ft_strdup(format);
		head = add_link(head, create_elem(flag));
	}
	return (head);
*/






