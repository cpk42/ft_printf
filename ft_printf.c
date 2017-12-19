/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:30:54 by ckrommen          #+#    #+#             */
/*   Updated: 2017/12/19 15:01:57 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_remalloc(char *str)
{
	char *new;

	if (str)
	{
		new = ft_strnew(ft_strlen(str) + 1);
		ft_memset((void *)new, '.', ft_strlen(str) + 1)
		new = ft_strcpy(new, str);
		free(str);
		return (new);
	}
	return (NULL);
}



char	*parse_format(char *format, char *res, va_list ap)
{
	res = ft_strnew(1);
	while (*format)
	{
		if (is_alpha(*format))
		{
			if (!*res)
				res = ft_remalloc(res);
			*res = *format;
			res++;
		}
		else if (!is_alpha(*format))
		{
			parse_flags(format);
		}
		format++;
	}
	return (res);
}

int ft_printf(char const *restrict format, ...)
{
	va_list ap;
	char *res;

	va_start(ap, format);
	parse_format((char *)format, res, ap);
	
	return (1);
}

int main(void)
{

	
	ft_printf("%i %i %c %s", 9, 8, 'c', "string");
	return 0;
}



/* print all non-negative args one at a time;
   all args are assumed to be of int type 
void printargs(const char *format, ...)
{
	va_list ap;
	int i;
	char *str;

	va_start(ap, format); 
	i = 4;
	str = (char *)format;
	while (i >= 0)
	{
		ft_putstr(str);
		str = va_arg(ap, char *);
		i--;
	}
	va_end(ap);
	putchar('\n');
}
*/
