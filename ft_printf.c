/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:30:54 by ckrommen          #+#    #+#             */
/*   Updated: 2017/12/18 20:31:31 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *restrict format, ...)
{
	va_list	ap;
	char	**c_store;
	void	*arg;
	int		i;

	i = 0;
	c_store = (char **)malloc(sizeof(char *) * 2048);
	va_start(ap, format);
	arg = va_arg(ap, char *);
	while (i < 4)
	{
		if (!*c_store[i])
			c_store[i] = ft_strnew(2048);
		c_store[i] = arg;
		arg = va_arg(ap, char *);
		printf("%s", arg);
		*c_store++;
		i++;
	}
	i = 0;
	while (c_store[i])
	{
		i++;
		ft_putnbr(i);
	}
	va_end(ap);
	return (1);
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
int main(void)
{
//	char *str;

//	str = malloc(sizeof(char *) * 6);
	
	ft_printf("asdsad%d %i %c %s", 9, 8, 'c', "string");
	return 0;
}
