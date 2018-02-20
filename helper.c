/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:07:27 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/19 17:11:24 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Reverse a string in place
*/

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
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
** Returns true or false whether or not a given character is found in a string
*/

int		ft_findchar(char c, char *search)
{
	while (*search)
	{
		if (*search == c)
			return (1);
		search++;
	}
	return (0);
}

/*
** prints w_char string to stdout
*/

void	ft_putwstr(wchar_t *str)
{
	wchar_t *p;

	p = str;
	while (*str)
		write(1, str++, 1);
}

/*
** used to print a space buffer if only a period is provided for precision
*/

int		print_buffer(t_tools tools, va_list ap)
{
	int ret;

	ret = 0;
	while (WIDTH--)
	{
		ft_putchar(ZERO ? '0' : 32);
		ret++;
	}
	va_arg(ap, void *);
	return (ret);
}
