/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:09:50 by ckrommen          #+#    #+#             */
/*   Updated: 2018/02/12 15:28:24 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Int value to Hexadecimal
*/

char	*ft_itoh(unsigned long long int nbr, t_tools tools, char *str)
{
	int i;

	i = 0;
	if (!nbr)
		str[i] = '0';
	if (TYPE == 'x' || TYPE == 'p')
	{
		while (nbr != 0)
		{
			str[i++] = "0123456789abcdef"[nbr % 16];
			nbr /= 16;
		}
	}
	else
		while (nbr != 0)
		{
			str[i++] = "0123456789ABCDEF"[nbr % 16];
			nbr /= 16;
		}
	if (HASH || TYPE == 'p')
		hash(tools, str);
	return (ft_strrev(str));
}

char	*ft_itoo(unsigned long long int nbr, t_tools tools, char *str)
{
	int i;

	i = 0;
	if (!nbr)
		str[0] = '0';
	while (nbr != 0)
	{
		str[i++] = (nbr % 8) + 48;
		nbr /= 8;
	}
	if (HASH)
		hash(tools, str);
	return (ft_strrev(str));
}


/*
** ULL to ascii
*/

char	*ft_ulltoa(__uint64_t nbr)
{
	int			length;
	__uint64_t	sign;
	char		*str;

	sign = nbr;
	length = 1;
	while (sign /= 10)
		length++;
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	while (--length >= 0)
	{
		str[length] = (nbr >= 10) ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
