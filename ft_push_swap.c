/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:00:34 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 14:23:55 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: remove stdio from .h
// cc -Wall -Wextra -Werror *.h *.c && ./a.out 43 56 12 0 -134 5455 -2

#include "ft_push_swap.h"

void	print_array(int *arr, int size, char c);

int	main(int argc, char *argv[])
{
	int	*arr_a;
	int	*arr_b;
	int	size_a;
	int	size_b;

	size_a = argc - 1;
	printf("Initial size: %d\n", argc -1);
	if (argc == 1)
		return (0);
	arr_a = is_valid(argc, argv);
	if (!arr_a)
		return (0);
	size_b = 0;
	arr_b = malloc(size_a * sizeof(int));
	if (!arr_b)
		return (0);
	// print_array(arr_a, size_a, 'a');
	quicksort(arr_a, size_a, arr_b, size_b);
}

void	print_array(int *arr, int size, char c)
{
	int	i;

	if (!arr || size < 1)
	{
		printf ("\nEmpty array: %c, nothing to print.\n\n", c);
		return ;
	}
	printf("\nPrinting array: %c\nsize: %d\n", c, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n\n");
}

// Testing
	// print_array(arr_a, size_a, 'a');
	// push(arr_b, &size_b, arr_a, &size_a);
	// push(arr_b, &size_b, arr_a, &size_a);
	// print_array(arr_a, size_a, 'a');
	// print_array(arr_b, size_b, 'b');
	// shift_left(arr_a, size_a);
	// shift_left(arr_a, size_a);
	// shift_left(arr_a, size_a);
	// print_array(arr_a, size_a, 'a');
	// shift_right(arr_b, size_b);
	// print_array(arr_b, size_b, 'b');
	// swap(arr_a, size_a);
	// print_array(arr_a, size_a, 'a');
