/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darguerr <darguerr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:36:07 by jeandrad          #+#    #+#             */
/*   Updated: 2025/05/13 17:18:18 by darguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
Ex01 fallo de norma: nombres en español.
*/
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
