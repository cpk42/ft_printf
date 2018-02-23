/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:19:45 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/22 16:16:38 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*
** Prints width and height for special cases
*/

int		ft_specialbuffer(t_tools tools, char *arg)
{
	int ret;

	ret = 0;
	if (!WIDTH)
		WIDTH = 1;
	while (--WIDTH && !MINUS)
	{
		ret++;
		ft_putchar(ZERO ? '0' : 32);
	}
	ft_putchar(arg[0]);
	ret++;
	while (WIDTH-- && MINUS)
	{
		ret++;
		ft_putchar(ZERO ? '0' : 32);
	}
	return (ret);
}
