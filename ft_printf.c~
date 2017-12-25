/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:30:54 by ckrommen          #+#    #+#             */
/*   Updated: 2017/12/19 17:26:50 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_remalloc(char *str)
{
	char *new;

	if (str)
	{
		printf("%zu\n", ft_strlen(str));
		new = ft_strnew(ft_strlen(str) + 1);
		ft_memset((void *)new, '.', ft_strlen(str) + 1);
		new = ft_strcpy(new, str);
		ft_strdel(&str);
		return (new);
	}
	return (NULL);
}

char	*parse_flags(char *flag, va_list ap)
{
	if (*flag == 's')
		return (va_arg(ap, char *));
	else if (*flag == 'S')
		return ("BROKEN");
	else if (*flag == 'p')
		return ("MEMORY");
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
	else if (*flag == 'u')
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

void	parse_format(char *format, char **res, va_list ap)
{
	int i;

	i = 0;
	while (*format)
	{
		if (ft_isalpha(*format) || *format == 32)
		{
			if (!*res)
				*res = ft_strnew(1);
			else if (!*res[i])
				*res = ft_remalloc(*res);
			*res[i] = *format;
			i++;
		}
		else if (*format == '%')
		{
			format++;
			*res = ft_strjoin(*res, parse_flags(format, ap));
			i = ft_strlen(*res);
		}
		format++;
	}
}

int ft_printf(char const *restrict format, ...)
{
	va_list ap;
	char *res;

	va_start(ap, format);
	parse_format((char *)format, &res, ap);
	ft_putstr(res);
	return (1);
}

int main(void)
{	
	ft_printf("as%i%s", 1, "string");
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
