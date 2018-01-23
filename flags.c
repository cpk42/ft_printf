/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 10:46:45 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/22 21:15:07 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** use the tools struct to deal with the width / zero flags
*/

void	width(char *str, t_tools tools, char *arg)
{
	int i;
	int j;

	j = ft_strlen(str);
	i = 0;
	while (MINUS == false && WIDTH-- > (int)ft_strlen(arg))
		str[j++] = ZERO == true ? '0' : ' ';
	while (arg[i])
	{
		str[j] = arg[i];
		i++;
		j++;
	}
	while (MINUS == true && WIDTH-- > (int)ft_strlen(arg))
		str[j++] = ZERO == true ? '0' : ' ';
}

/*
** use the tools struct to deal with precision
*/

char	*precision(t_tools tools, char *arg)
{
	int		i;
	char	*mem;

	i = 0;
	mem = ft_strnew(ft_strlen(arg) + PREC+1);
	mem[i] = (i == 0 && PLUS && !NEG) ? '+' : '0';
	mem[i] = (NEG) ? '-' : mem[i];
	mem[i] = (SPACE && !NEG) ? ' ' : mem[i];
	i = (mem[i] == '-' || mem[i] == '+' || mem[i] == ' ') ? i+1 : i;
	while (PREC-- > (int)ft_strlen(arg))
	{
		mem[i] = '0';
		i++;
	}
	while (*arg)
	{
		mem[i] = *arg;
		i++;
		arg++;
	}
	return (mem);
}

/*
** handle the hash flag
*/

void		hash(t_tools tools, char *arg)
{
	if (TYPE == 'p')
	{
		arg[ft_strlen(arg)] = 'x';
		arg[ft_strlen(arg)] = '0';
	}
	if (TYPE == 'o' || TYPE == 'O')
		arg[ft_strlen(arg)] = '0';
}
