/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:00:34 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 10:09:47 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: remove stdio from .h

#include "ft_push_swap.h"

void	print_array(int *arr, int size);

int	main(int argc, char *argv[])
{
	int	*arr_a;
	int	*arr_b;
	int	size;

	size = argc - 1;
	if (argc == 1)
		return (0);
	arr_a = is_valid(argc, argv);
	if (!arr_a)
		return (0);
	arr_b = init(size);
	print_array(arr_a, size);
	push(arr_b, size, arr_a, size);
	push(arr_b, size, arr_a, size);
	print_array(arr_a, size);
	print_array(arr_b, size);
	shift_right(arr_a, size);
	print_array(arr_a, size);
	shift_left(arr_a, size);
	shift_left(arr_a, size);
	shift_left(arr_a, size);
	print_array(arr_a, size);
	swap(arr_a, size);
	swap(arr_b, size);
	print_array(arr_a, size);
	print_array(arr_b, size);
}

void	print_array(int *arr, int size)
{
	int	actual_size;
	int	i;

	actual_size = get_actual_size(arr, size);
	if (!arr || size < 1 || actual_size < 1)
	{
		printf ("\nEmpty array, nothing to print.\n\n");
		return ;
	}
	printf("\nPrinting array\nsize: %d\nactual size: %d\n", size, actual_size);
	i = 0;
	while (i < actual_size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n\n");
}
