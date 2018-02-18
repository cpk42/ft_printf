/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 10:46:45 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/17 20:16:39 by ckrommen         ###   ########.fr       */
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

	j = 0;
	i = 0;
//	ft_putendl("\nARG");
//	ft_putendl(arg);
	while (MINUS == false && WIDTH-- > (int)ft_strlen(arg))
	{
//		printf("\nCUR WIDTH: %s\n", ft_itoa(WIDTH));
		str[i] = ZERO ? '0' : 32;
		i++;
	}
	while (arg[j])
	{
		str[i] = arg[j];
		i++;
		j++;
	}
	while (MINUS == true && WIDTH-- > (int)ft_strlen(arg))
	{
//		printf("\nCUR MINUS WIDTH: %s strlen: %zu ARG: %s\n", ft_itoa(WIDTH), ft_strlen(arg), arg);
		str[i] = ZERO ? '0' : 32;
		i++;
	}
}

/*
** use the tools struct to deal with precision
*/

char	*precision(t_tools tools, char *arg, int j)
{
	int		i;
	char	*str;

	str = ft_strnew(PREC + ft_strlen(arg));
	ft_bzero(str, PREC + ft_strlen(arg));
//	printf("\nPRECISION: %d\n", PREC);
	if (SPACE && !NEG)
		str[0] = ' ';
	else if (PLUS && !NEG)
		str[0] = '+';
	else if (NEG)
		str[0] = '-';
	i = str[0] == ' ' || str[0] == '-' || str[0] == '+' ? 1 : 0;
	while (PREC > (int)ft_strlen(arg))
	{
		str[i] = ZERO ? '0' : 32;
		i++;
		PREC--;
	}
	while (arg[j] && PREC--)
	{
		str[i] = arg[j];
		i++;
		j++;
	}
//	printf("\nstr: %s arg: %s\n", str, arg);
	return (str);
}
/*
char	*precision(t_tools tools, char *arg)
{
	char *str;
	int	i;
	int j;

	j = 0;
//	i = 0;
	str = ft_strnew(PREC + ft_strlen(arg));
//	i = (str[0] == ' ' || str[0] == '-' || str[0] == '+') ? 1 : 0;
//	PREC = (str[0] == ' ' || str[0] == '-' || str[0] == '+' && ) ? PREC-1 : PREC;
//	printf("PREC: %d\n", PREC);
//	if ()
//	if (PLUS || NEG)
//	{
//		str[i] = PLUS ? '+' : '-';
//		str[i] =  (SPACE && !NEG) ? ' ' : str[i];
//		i++;
//	}
	if (PLUS || NEG || SPACE)
	{
		str[0] = PLUS ? '+' : str[0];
		str[0] = SPACE ? 32 : str[0];
		str[0] = NEG ? '-' : str[0];
//		PREC--;
	}
	i = (str[0] == ' ' || str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (PREC-- > (int)ft_strlen(arg))
	{
		str[i] = TYPE == 's' ? ' ' : '0';
		i++;
	}
	while (*arg && PREC-- >= 0)
	{
		str[i] = arg[j];
		i++;
		j++;
	}
	return (str);
}
*/
/*
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


char	*precision(t_tools tools, char *arg)
{
	char *mem;
	int i;

	i = 0;
	mem = ft_strnew(PREC + ft_strlen(arg));
	if (i == 0 && PLUS && !NEG)
		mem[i] = '+';
	else if (NEG)
		mem[i] = '-';
	else if (SPACE && !NEG)
		mem[i] = ' ';
	i = (mem[i] == '-' || mem[i] == '+' || mem[i] == ' ') ? i+1 : i;
	while (PREC > (int)ft_strlen(arg))
	{
		mem[i] = TYPE != 's' ? '0' : 32;
		PREC--;
		i++;
	}
	while (PREC > 0 && *arg)
	{
		mem[i] = *arg;
		i++;
		arg++;
		PREC--;
	}
	return (mem);
	}*/
/*
char	*precision(t_tools tools, char *arg)
{
	int		i;
	char	*mem;

	i = 0;
	mem = ft_strnew(ft_strlen(arg) + WIDTH + PREC);
	mem[i] = (i == 0 && PLUS && !NEG) ? '+' : '0';
	mem[i] = (NEG) ? '-' : mem[i];
	mem[i] = (SPACE && !NEG) ? ' ' : mem[i];
	
	}*/
 /*
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
	if (!PREC)
		PREC = ft_strlen(arg);
	while (PREC > (int)ft_strlen(arg))
	{
		mem[i] = TYPE != 's' ? '0' : 32;
		PREC--;
		i++;
	}
	while (*arg && PREC)
	{
		mem[i] = *arg;
		i++;
		arg++;
		PREC--;
	}
	return (mem);
}
 */
/*
** handle the hash flag
*/

void		hash(t_tools tools, char *arg)
{
	if (TYPE == 'p' || TYPE == 'x' || TYPE == 'X')
	{
		arg[ft_strlen(arg)] = 'x';
		arg[ft_strlen(arg)] = '0';
	}
	if (TYPE == 'o' || TYPE == 'O')
		arg[ft_strlen(arg)] = '0';
}
