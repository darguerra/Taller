/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:39:03 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:39:58 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
