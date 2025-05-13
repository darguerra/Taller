/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darguerr <darguerr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:17:03 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/13 17:41:08 by darguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
ex04
Valgrind dice que hay un leak porque estamos haciendo un malloc y no lo estamos haciendo un free
*/

void	process_input(const char *input)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc((strlen(input) + 1) * sizeof(char));
	i = 0;
	if (buffer == NULL)
	{
		write(2, "Error al asignar memoria\n", 25);
		return ;
	}
	buffer = toupper(buffer);
	while (input[i] != '\0')
	{
		buffer[i] = input[i];
		i++;
	}
	buffer[strlen(input)] = '\0';
	write(1, buffer, strlen(buffer));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Uso: ./programa <mensaje>\n", 26);
		return (1);
	}
	while (i < argc)
	{
		process_input(argv[i]);
		i++;
	}
	return (0);
}
