/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:36:07 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/12 16:36:20 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	imprimir_cuadrado(long cuadrado);

void	calculate_square(int num)
{
	long	cuadrado;

	cuadrado = num * num;
	imprimir_cuadrado(cuadrado);
}

void	imprimir_cuadrado(long cuadrado)
{
	printf("El cuadrado del número es: %ld\n", cuadrado);
}
