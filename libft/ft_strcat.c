/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:50:15 by ckrommen          #+#    #+#             */
/*   Updated: 2017/09/24 14:57:06 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		x;

	x = ft_strlen(s1);
	while (*s2 != '\0')
		s1[x++] = *s2++;
	s1[x] = '\0';
	return (s1);
}
