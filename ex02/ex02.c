/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darguerr <darguerr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:57:45 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/13 17:32:52 by darguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
ex02
variable i no inicializada (i = 1;)
*/

void	print_uneven_numbers(void)
{
	char	buffer[4];
	int		i;
	int		len;

	while (i <= 100)
	{
		len = 0;
		if (i >= 100)
		{
			buffer[len++] = '1';
			buffer[len++] = '0';
			buffer[len++] = '0';
		}
		else if (i >= 10)
		{
			buffer[len++] = '0' + (i / 10);
			buffer[len++] = '0' + (i % 10);
		}
		else
			buffer[len++] = '0' + i;
		buffer[len++] = '\n';
		write(STDOUT_FILENO, buffer, len);
		i += 2;
	}
}
