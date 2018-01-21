/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:25:38 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/20 16:15:13 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts args that contain characters
*/

void	convert_char(t_tools tools, char *str, va_list ap)
{
	char	temp[1024];

	if (TYPE == 's')
		ft_strcpy(temp, va_arg(ap, char *));
	else if (TYPE == 'c')
		ft_strcpy(temp, va_arg(ap, char *));
	use_tools(str, tools, temp);
}

/*
** Converts args containg ints
*/

void	convert_int(t_tools tools, char *str, va_list ap)
{
	char temp[1024];
	char *mem;

	if (TYPE == 'i' || TYPE == 'd')
	{
		mem = ft_itoa(va_arg(ap, int));
		ft_strcpy(temp, mem);
		ft_strdel(&mem);
	}
	use_tools(str, tools, temp);
}
