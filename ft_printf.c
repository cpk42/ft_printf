/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:30:54 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/02 11:53:31 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_remalloc(char *str)
{
	char *new;

	if (str)
	{
		new = ft_strnew(ft_strlen(str) + 1);
		ft_memset((void *)new, '.', ft_strlen(str) + 1);
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
	else
		return (parse_flags2(flag, ap));
}

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
			  res = ft_strdup(parse_flags(format, ap));
			else
			  res = ft_strjoin(res, parse_flags(format, ap));
			i = ft_strlen(res);
		}
		format++;
	}
	return (res);
}

int ft_printf(char const *restrict format, ...)
{
	va_list ap;
	char *res;

	res = NULL;
	va_start(ap, format);
	res = parse_format((char *)format, res, ap);
	ft_putstr(res);
	va_end(ap);
	return (1);
}

int main(void)
{
  ft_printf("%p%S", 2, 1);
  return 0;
}
