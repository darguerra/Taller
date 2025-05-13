/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:34:29 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:35:07 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	safe_atoi(const char *str, int *out)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[0] == '\0' || (str[0] == '-' && str[1] == '\0'))
		return (0);
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

void	calculate(const char *op, const char *a_str, const char *b_str)
{
	char	buffer[100];
	int		result;
	int		a;
	int		b;

	if (!safe_atoi(a_str, &a) || !safe_atoi(b_str, &b))
	{
		write(2, "Error: Invalid number input\n", 28);
		return ;
	}
	if (strcmp(op, "add") == 0)
	{
		result = a + b;
		snprintf(buffer, sizeof(buffer), "Resultado: %d\n", result);
	}
	else if (strcmp(op, "mul") == 0)
	{
		result = a * b;
		snprintf(buffer, sizeof(buffer), "Resultado: %d\n", result);
	}
	else
	{
		snprintf(buffer, sizeof(buffer), "Operacion desconocida\n");
	}
	write(1, buffer, strlen(buffer));
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(2, "Uso: ./programa <operacion> <num1> <num2>\n", 42);
		return (1);
	}
	calculate(argv[1], argv[2], argv[3]);
	return (0);
}
