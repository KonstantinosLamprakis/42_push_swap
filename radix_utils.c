// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   radix_utils.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/25 08:50:46 by klamprak          #+#    #+#             */
// /*   Updated: 2024/03/26 03:02:23 by klamprak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_push_swap.h"

// static void	push_min_in_5(int *arr_a, int *size_a, int *arr_b, int *size_b);
// static void	push_min_in_4(int *arr_a, int *size_a, int *arr_b, int *size_b);
// static void	sort_3_ints(int *arr, int size);

// // returns a new array
// // each element corresponds to the element with same index in arr_a
// // it holds the position of this element in the sorted array
// // if we sort the new array, its same as if we sort the initial one
// // we do it to "convert" each value of arr_a to positive
// // ex. arr_a = {-5 , 3, 0, -8, 6} -> result = {1, 3, 2, 0, 4}
// // explain: -8 -> 0, -5 -> 1, 0 -> 2, 3 -> 3, 6 -> 4
// void	create_index(int **arr_a, int size_a)
// {
// 	int	i;
// 	int	*result;
// 	int	j;

// 	if (!arr_a || !(*arr_a) || size_a == 0)
// 		return (NULL);
// 	result = malloc(sizeof(int) * size_a);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i < size_a)
// 	{
// 		j = 0;
// 		result[i] = 0;
// 		while (j < size_a)
// 		{
// 			if ((*arr_a)[j] < (*arr_a)[i])
// 				result[i]++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(*arr_a);
// 	*arr_a = result;
// }

// // check if the size is less than or equal to 5 and sort this list
// // 2 ops for size = 3, 6 for size = 4 and 10 for size = 5
// int	sort_less_than_5(int *arr_a_b[2], int *size_a_b[2])
// {
// 	if (!arr_a_b[0] || !arr_a_b[1] || *size_a_b[0] > 5 || *size_a_b[1] <= 0)
// 		return (0);
// 	if (*size_a_b[0] == 2 && arr_a_b[0][0] > arr_a_b[0][1])
// 		swap(arr_a_b[0], *(size_a_b[0]), 'a');
// 	if (*(size_a_b[0]) == 1 || *(size_a_b[0]) == 2)
// 		return (0);
// 	if (*(size_a_b[0]) == 3)
// 		sort_3_ints(arr_a_b[0], *(size_a_b[0]));
// 	else if (size_a_b[0] == 4)
// 	{
// 		push_min_in_4(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 		sort_3_ints(size_a_b[0], *(size_a_b[0]));
// 		push(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 	}
// 	else if (size_a_b[0] == 5)
// 	{
// 		push_min_in_5(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 		push_min_in_4(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 		sort_3_ints(arr_a_b[0], *(size_a_b[0]));
// 		push(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 		push(arr_a_b[0], size_a_b[0], arr_a_b[1], size_a_b[1]);
// 	}
// 	return (0);
// }

// // 6 possible cases 123 - 132 - 231 - 213 - 312 - 321
// // max 2 operations
// static void	sort_3_ints(int *arr, int size)
// {
// 	if (is_sorted(arr, size))
// 		return (1);
// 	if (arr[0] < arr[2] && arr[2] < arr[1])
// 	{
// 		swap(arr, size);
// 		shift_left(arr, size);
// 	}
// 	else if (arr[0] > arr[2] && arr[1] > arr[0])
// 		shift_right(arr, size);
// 	else if (arr[0] > arr[1] && arr[2] > arr[0])
// 		swap(arr, size);
// 	else if (arr[0] > arr[2] && arr[2] > arr[1])
// 		shift_left(arr, size);
// 	else if (arr[0] > arr[1] && arr[1] > arr[2])
// 	{
// 		shift_left(arr, size);
// 		shift_left(arr, size);
// 	}
// }

// // max 3 ops
// // push the minimum value of arr_a to arr_b from the first 4 values
// static void	push_min_in_4(int *arr_a, int *size_a, int *arr_b, int *size_b)
// {
// 	int	i;
// 	int	min;

// 	i = 0;
// 	min = 0;
// 	while (++i < 4)
// 		if (arr_a[i] < arr_a[min])
// 			min = i;
// 	if (min == 0)
// 		push(arr_b, size_b, arr_a, size_a);
// 	else if (min == 1)
// 	{
// 		shift_left(arr_a, *size_a);
// 		push(arr_b, size_b, arr_a, size_a);
// 	}
// 	else if (min == 2)
// 	{
// 		shift_left(arr_a, *size_a);
// 		shift_left(arr_a, *size_a);
// 		push(arr_b, size_b, arr_a, size_a);
// 	}
// 	if (min == 0 || min == 1 || min == 2)
// 		return ;
// 	shift_right(arr_a, *size_a);
// 	push(arr_b, size_b, arr_a, size_a);
// }

// // max 3 ops
// // push the minimum value of arr_a to arr_b from the first 5 values
// static void	push_min_in_5(int *arr_a, int *size_a, int *arr_b, int *size_b)
// {
// 	int	i;
// 	int	min;

// 	i = 0;
// 	min = 0;
// 	while (++i < size_a)
// 		if (arr_a[i] < arr_a[min])
// 			min = i;
// 	if (min == 0 || min == 1 || min == 2)
// 		push_min_in_4(arr_a, size_a, arr_b, size_b);
// 	else if (min == 3)
// 	{
// 		shift_right(arr_a, *size_a);
// 		shift_right(arr_a, *size_a);
// 		push(arr_b, size_b, arr_a, size_a);
// 	}
// 	else if (min == 4)
// 	{
// 		shift_right(arr_a, *size_a);
// 		push(arr_b, size_b, arr_a, size_a);
// 	}
// }
