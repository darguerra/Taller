/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:30:36 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:31:09 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	process_input(const char *input)
{
	int	i;

	i = 0;
	write(1, "Processing input...\n", 20);
	if (strcmp(input, "loop") == 0)
	{
		while (i)
		{
			putchar(input[i]);
		}
	}
	else if (strcmp(input, "exit") == 0)
	{
		write(1, "Exiting...\n", 15);
		return ;
	}
	else
	{
		write(1, input, strlen(input));
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
	{
		write(2, "Uso: ./programa <mensaje>\n", 26);
		return (1);
	}
	while (i < argc)
	{
		i++;
		process_input(argv[i]);
	}
	return (0);
}
