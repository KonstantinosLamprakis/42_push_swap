/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:00:34 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 03:20:59 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: remove stdio from .h
// cc -Wall -Wextra -Werror *.h *.c && ./a.out
// TODO delete print_array func from .h

#include "ft_push_swap.h"

void	print_array(int *arr, int size, char c);

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks.a_size = argc - 1;
	printf("Initial size: %d\n", stacks.a_size);
	if (argc == 1)
		return (0);
	stacks.a = is_valid(argc, argv);
	if (!stacks.a)
		return (0);
	stacks.b_size = 0;
	stacks.b = malloc(stacks.a_size * sizeof(int));
	if (!stacks.b)
	{
		free (stacks.a);
		return (0);
	}
	puts("Initial Array");
	print_array(stacks.a, stacks.a_size, 'a');
	create_index(&stacks.a, stacks.a_size);
	puts("Index Array");
	print_array(stacks.a, stacks.a_size, 'a');
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
	// print_array(stacks.a, stacks.a_size, 'a');
	// push_b(stacks, &stacks.a_size, &stacks.b_size);
	// push_b(stacks, &stacks.a_size, &stacks.b_size);
	// print_array(stacks.a, stacks.a_size, 'a');
	// print_array(stacks.b, stacks.b_size, 'b');
	// shift_left(stacks.a, stacks.a_size, 'a');
	// shift_left(stacks.a, stacks.a_size, 'a');
	// shift_left(stacks.a, stacks.a_size, 'a');
	// print_array(stacks.a, stacks.a_size, 'a');
	// shift_right(stacks.b, stacks.b_size, 'b');
	// print_array(stacks.b, stacks.b_size, 'b');
	// swap(stacks.a, stacks.a_size, 'a');
	// push_a(stacks, &stacks.a_size, &stacks.b_size);
	// push_a(stacks, &stacks.a_size, &stacks.b_size);
	// print_array(stacks.a, stacks.a_size, 'a');
