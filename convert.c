/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:25:38 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/25 18:44:29 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts args that contain characters
*/

void	convert_char(t_tools tools, char *str, va_list ap)
{
	char	temp[1024];

	ft_bzero(temp, 1024);
	if (TYPE == 's')
		ft_strcpy(temp, va_arg(ap, char *));
	else if (TYPE == 'c')
		temp[0] = va_arg(ap, int);
	else if (TYPE == '%')
		temp[0] = '%';
	use_tools(str, tools, temp);
}

/*
** Converts args containg ints
*/

void	convert_int(t_tools tools, char *str, va_list ap)
{
	char temp[1024];
	char *mem;
	long long i;

	ft_bzero(temp, 1024);
	i = use_format(tools, ap);
	if (i == LL_MIN)
		NEG = true;
	if ((TYPE == 'i' || TYPE == 'd') && i != LL_MAX)
	{
		NEG = i < 0 ? true : false;
		i *= i < 0 ? -1 : 1;
	}
	if (i)
	{
		mem = ft_ulltoa(i);
		ft_strcpy(temp, mem);
		ft_strdel(&mem);
	}
	use_tools(str, tools, temp);
}

/*
** convert hex and ptr
*/

void	convert_ptr(t_tools tools, char *str, va_list ap)
{
	unsigned long long int nbr;
	char	temp[1024];

	ft_bzero(temp, 1024);
	nbr = va_arg(ap, unsigned long long int);
	if (TYPE == 'o' || TYPE == 'O')
		ft_itoo(nbr, tools, temp);
	else
		ft_itoh(nbr, tools, temp);
	use_tools(str, tools, temp);
}

/*
** Convert ull
*/

void	convert_ull(t_tools tools, char *str, va_list ap)
{
	unsigned long long int i;
	char	*mem;
	char	temp[1024];

	i = ull_use_format(tools, ap);
	if (i)
	{
		mem = ft_ulltoa(i);
		ft_strcpy(temp, mem);
		ft_strdel(&mem);
	}
	use_tools(str, tools, temp);
}
