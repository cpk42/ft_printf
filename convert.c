/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:25:38 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/18 21:07:34 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts args that contain characters
*/

int	convert_char(t_tools tools, va_list ap)
{
	char	temp[1024];
	int		ret;

	ft_bzero(temp, 1024);
	if (TYPE == 's')
		ft_strcpy(temp, va_arg(ap, char *));
	else if (TYPE == 'c')
		temp[0] = va_arg(ap, int);
	else if (TYPE == '%')
		temp[0] = '%';
	ret = use_tools(tools, temp);
	return (ret);
}

/*
** Converts args containg ints
*/

int	convert_int(t_tools tools, va_list ap)
{
	char		temp[1024];
	char		*mem;
	int			ret;
	long long	i;

	ft_bzero(temp, 1024);
	i = use_format(tools, ap);
	if (i == LL_MIN)
		NEG = TRUE;
	if ((TYPE == 'i' || TYPE == 'd') && i != LL_MAX)
	{
		NEG = i < 0 ? TRUE : FALSE;
		i *= i < 0 ? -1 : 1;
	}
	if (i)
	{
		mem = ft_ulltoa(i);
		ft_strcpy(temp, mem);
		ft_strdel(&mem);
	}
	else if (!i)
		temp[0] = '0';
	ret = use_tools(tools, temp);
	return (ret);
}

/*
** convert hex and ptr
*/

int	convert_ptr(t_tools tools, va_list ap)
{
	unsigned long long int	nbr;
	char					temp[1024];
	int						ret;

	ft_bzero(temp, 1024);
	nbr = va_arg(ap, unsigned long long int);
	if (TYPE == 'o' || TYPE == 'O')
		ft_itoo(nbr, tools, temp);
	else
		ft_itoh(nbr, tools, temp);
	ret = use_tools(tools, temp);
	return (ret);
}

/*
** Convert ull
*/

int	convert_ull(t_tools tools, va_list ap)
{
	unsigned long long int	i;
	char					*mem;
	char					temp[1024];
	int						ret;

	i = ull_use_format(tools, ap);
	if (i)
	{
		mem = ft_ulltoa(i);
		ft_strcpy(temp, mem);
		ft_strdel(&mem);
	}
	ret = use_tools(tools, temp);
	return (ret);
}

/*
** Convert wide char
*/

int	convert_wchar(t_tools tools, va_list ap)
{
	wchar_t	*mem;
	char	str[1024];

	ft_bzero(str, 1024);
	mem = (wchar_t *)va_arg(ap, wchar_t *);
	ft_putchar(TYPE);
	return (1);
}
