/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:20:47 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:30:14 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	reverse_and_print(const char *input)
{
	char	*buffer;
	size_t	len;
	size_t	i;

	len = strlen(input);
	buffer = (char *)malloc(strlen(input) + 1);
	i = 0;
	while (i < len)
	{
		buffer[i] = input[len - i - 1];
		i++;
	}
	buffer[len] = '\0';
	write(1, buffer, len);
	write(1, "\n", 1);
	free(buffer);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Uso: ./programa <mensaje1> <mensaje2> ...\n", 42);
		return (1);
	}
	while (i < argc)
	{
		reverse_and_print(argv[i]);
		i++;
	}
	return (0);
}
