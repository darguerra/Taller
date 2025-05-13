/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darguerr <darguerr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:39:03 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/13 17:35:37 by darguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Ex03: el principal fallo era la falta de protección de malloc
Pasamos al 4!!
*/

static int	ft_nsize(long i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i = -i;
		count++;
	}
	while (i >= 10)
	{
		i /= 10;
		count++;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nsize(n);
	str = (char *) malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[--i] = ((n % 10) * -1) + '0';
		else if (n > 0)
			str[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
