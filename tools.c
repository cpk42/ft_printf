/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:44:31 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/20 16:04:52 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tools	reset_tools()
{
	t_tools tools;

	PLUS = false;
	MINUS = false;
	ZERO = false;
	SPACE = false;
	HASH = false;
	PREC = false;
	TYPE = 0;
	WIDTH = 0;
	PREC = 0;
	ARG = 0;
	RET = 0;
	LEN = 0;
	return (tools);
}

void	use_tools(char *str, t_tools tools, char *arg)
{
	width(str, tools, arg);
}
