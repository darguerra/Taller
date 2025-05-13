/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darguerr <darguerr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:33:05 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/13 18:12:03 by darguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
ex08 el main no hace las comprobaciones de la cantidad de argumentos que deberia ser
if (argc < 3)
	{
		print_string("Uso: ./programa <numero>\n");
		return (1);
	}

	Ex08: línea 59 : falta sumar 26 + 1 por el carácter nulo

	no libera cuando !buffer

	
	ex08: si el repeat recibe un numero muy grande, me dice que times must be greater than 0 (imagino que tiene que ver con lo del valor minimo de un entero, que es -214 no me acuerdo de mas XD) ????
*/

void	print_string(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	to_uppercase(const char *input)
{
	char	c;
	size_t	i;

	i = 0;
	while (input[i] != '\0')
	{
		c = toupper(input[i]);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	repeat_alphabet(int times)
{
	int			i;
	const char	*alphabet;
	char		*buffer;

	i = 0;
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	if (times <= 0)
	{
		write(2, "Error: times must be greater than 0\n", 36);
		return ;
	}
	buffer = (char *)malloc(times * 26);
	if (buffer == NULL)
	{
		write(2, "Error: memory allocation failed\n", 33);
		return ;
	}
	while (i < times)
	{
		memcpy(buffer + (i * 26), alphabet, 26);
		i++;
	}
	write(1, buffer, times * 26);
	write(1, "\n", 1);
	free(buffer);
}

void	process_arguments(int argc, char **argv)
{
	int	times;

	if (argc < 3)
	{
		write(2, "Uso: ./programa <opcion> <valor>\n", 33);
		return ;
	}
	if (strcmp(argv[1], "toupper") == 0)
	{
		to_uppercase(argv[2]);
	}
	else if (strcmp(argv[1], "repeat") == 0)
	{
		times = atoi(argv[2]);
		repeat_alphabet(times);
	}
	else
	{
		write(2, "Opcion desconocida\n", 19);
	}
}

int	main(int argc, char **argv)
{
	process_arguments(argc, argv);
	return (0);
}
