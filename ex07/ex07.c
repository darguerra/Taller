/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:31:56 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:32:12 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	print_string(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_number(int number)
{
	char	buffer[12];
	int		i;

	i = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if (number == 0)
	{
		buffer[i++] = '0';
	}
	while (number > 0)
	{
		buffer[i++] = (number % 10) + '0';
		number /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}

void	process_number(const char *input)
{
	int	number;

	number = atoi(input);
	print_string("Number: ");
	print_number(number);
	print_string("\n");
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		print_string("Uso: ./programa <numero>\n");
		return (1);
	}
	while (i < argc)
	{
		process_number(argv[i]);
		i++;
	}
	return (0);
}
