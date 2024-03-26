/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:50:46 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 05:54:48 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_3_ints(int *arr, int size, char c);
static void	push_min_in_4(t_stacks stacks, char c);
static void	push_min_in_5(t_stacks stacks, char c);

// check if the size is less than or equal to 5 and sort this list
// 2 ops for size = 3, 6 for size = 4 and 10 for size = 5
// returns 0 if didn't sort elements, size <=0 || size > 5
// otherwise returns 1
int	sort_less_than_5(t_stacks *stacks)
{
	if (!stacks->a || !stacks->b || stacks->a_size > 5 || stacks->a_size <= 0)
		return (0);
	if (stacks->a_size == 2 && stacks->a[0] > stacks->a[1])
		swap(stacks->a, stacks->a_size, 'a');
	if (stacks->a_size == 1 || stacks->a_size == 2)
		return (1);
	if (stacks->a_size == 3)
		sort_3_ints(stacks->a, stacks->a_size, 'a');
	else if (stacks->a_size == 4)
	{
		push_min_in_4(*stacks, 'a');
		sort_3_ints(stacks->a, stacks->a_size, 'a');
		push_a(*stacks);
	}
	else if (stacks->a_size == 5)
	{
		push_min_in_5(*stacks, 'a');
		push_min_in_4(*stacks, 'a');
		sort_3_ints(stacks->a, stacks->a_size, 'a');
		push_a(*stacks);
		push_a(*stacks);
	}
	return (1);
}

// 6 possible cases 123 - 132 - 231 - 213 - 312 - 321
// max 2 operations
static void	sort_3_ints(int *arr, int size, char c)
{
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		swap(arr, size, c);
		shift_left(arr, size, c);
	}
	else if (arr[0] > arr[2] && arr[1] > arr[0])
		shift_right(arr, size, c);
	else if (arr[0] > arr[1] && arr[2] > arr[0])
		swap(arr, size, c);
	else if (arr[0] > arr[2] && arr[2] > arr[1])
		shift_left(arr, size, c);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		shift_left(arr, size, c);
		swap(arr, size, c);
	}
}

// max 3 ops
// push the minimum value of stacks.a to stacks.b from the first 4 values
static void	push_min_in_4(t_stacks stacks, char c)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < 4)
		if (stacks.a[i] < stacks.a[min])
			min = i;
	if (min == 0)
		push_b(stacks);
	else if (min == 1)
	{
		shift_left(stacks.a, stacks.a_size, c);
		push_b(stacks);
	}
	else if (min == 2)
	{
		shift_left(stacks.a, stacks.a_size, c);
		shift_left(stacks.a, stacks.a_size, c);
		push_b(stacks);
	}
	if (min == 0 || min == 1 || min == 2)
		return ;
	shift_right(stacks.a, stacks.a_size, c);
	push_b(stacks);
}

// max 3 ops
// push the minimum value of stacks.a to stacks.b from the first 5 values
static void	push_min_in_5(t_stacks stacks, char c)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < stacks.a_size)
		if (stacks.a[i] < stacks.a[min])
			min = i;
	if (min == 0 || min == 1 || min == 2)
		push_min_in_4(stacks, c);
	else if (min == 3)
	{
		shift_right(stacks.a, stacks.a_size, c);
		shift_right(stacks.a, stacks.a_size, c);
		push_b(stacks);
	}
	else if (min == 4)
	{
		shift_right(stacks.a, stacks.a_size, c);
		push_b(stacks);
	}
}

// returns a new arr, each elem corresp. to the elem with same index in arr_a
// it holds the position of this element in the sorted array
// if we sort the new array, its same as if we sort the initial one
// we do it to "convert" each value of arr_a to positive
// ex. arr_a = {-5 , 3, 0, -8, 6} -> result = {1, 3, 2, 0, 4}
// explain: -8 -> 0, -5 -> 1, 0 -> 2, 3 -> 3, 6 -> 4
void	create_index(int **arr_a, int size_a)
{
	int	i;
	int	*result;
	int	j;

	if (!arr_a || !(*arr_a) || size_a == 0)
		return ;
	result = malloc(sizeof(int) * size_a);
	if (!result)
		return ;
	i = 0;
	while (i < size_a)
	{
		j = 0;
		result[i] = 0;
		while (j < size_a)
		{
			if ((*arr_a)[j] < (*arr_a)[i])
				result[i]++;
			j++;
		}
		i++;
	}
	free(*arr_a);
	*arr_a = result;
}
