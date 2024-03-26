/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:00:34 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 06:23:20 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -Wall -Wextra -Werror *.h *.c && ./a.out

#include "ft_push_swap.h"

void	print_array(int *arr, int size, char c);

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks.a_size = argc - 1;
	stacks.b_size = 0;
	stacks.a_size_ptr = &stacks.a_size;
	stacks.b_size_ptr = &stacks.b_size;
	if (argc == 1)
		return (0);
	stacks.a = is_valid(argc, argv);
	if (!stacks.a)
		return (0);
	stacks.b = malloc(stacks.a_size * sizeof(int));
	if (!stacks.b)
	{
		free (stacks.a);
		return (0);
	}
	create_index(&stacks.a, stacks.a_size);
	if (!sort_less_than_5(&stacks))
		radix(&stacks);
	if (stacks.a)
		free(stacks.a);
	if (stacks.b)
		free(stacks.b);
	return (0);
}

// void	print_array(int *arr, int size, char c)
// {
// 	int	i;

// 	if (!arr || size < 1)
// 	{
// 		printf ("\nEmpty array: %c, nothing to print.\n\n", c);
// 		return ;
// 	}
// 	printf("\nPrinting array: %c\nsize: %d\n", c, size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n\n");
// }

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
