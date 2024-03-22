/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:09:48 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 15:50:10 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// returns 0 on error, 1 on success of sorting the list arr_a
// TODO double check that there isnt already a pivot in pivot_arr before add one
// TODO delete print_array func from .h
int	quicksort(int *arr_a, int size_a, int *arr_b, int size_b)
{
	int	*pivot_arr;
	int	size_p;
	int	pivot;
	int	is_sort;
	int	k;

	if (!arr_a || !arr_b || !size_a)
		return (0);
	pivot_arr = malloc(sizeof(int) * size_a);
	if (!pivot_arr)
		return (0);
	size_p = 0;
	print_array(arr_a, size_a, 'a');
	print_array(arr_b, size_b, 'b');
	puts("-----0----");
	while (size_a != 0)
	{
		pivot_arr[size_p++] = arr_a[0];
		pivot = arr_a[0];
		shift_left(arr_a, size_a);
		while (!is_included(pivot_arr, size_p, arr_a[0]))
		{
			if (arr_a[0] < pivot)
			{
				push(arr_b, &size_b, arr_a, &size_a);
				continue;
			}
			shift_left(arr_a, size_a);
		}
		push(arr_b, &size_b, arr_a, &size_a);
	}
	print_array(arr_a, size_a, 'a');
	print_array(arr_b, size_b, 'b');
	print_array(pivot_arr, size_p, 'p');
	puts("-----1----");
	pivot = 1;
	k = 1;
	is_sort = is_sorted(arr_b, size_b);
	while (!is_sort && ++k < 10)
	{
		if (pivot)
			is_sort = sort_stack(arr_b, &size_b, arr_a, &size_a, pivot_arr, &size_p);
		else
			is_sort = sort_stack(arr_a, &size_a, arr_b, &size_b, pivot_arr, &size_p);
		pivot = !pivot;
		print_array(arr_a, size_a, 'a');
		print_array(arr_b, size_b, 'b');
		print_array(pivot_arr, size_p, 'p');
		printf("-----%d----", k);
	}
	return (1);
}

int	sort_stack(int *arr_src, int *size_s, int *arr_dst, int *size_d, int *pivot_arr, int *size_pivot)
{
	int	is_small_to_big;
	int	size_p;
	int	pivot;
	int	i;
	int	j;
	int	size_src;
	int	size_dst;

	size_dst = *size_d;
	size_src = *size_s;
	if (is_sorted(arr_src, size_src))
	{
		puts("\n\n^^^^^^^^^Sorted a^^^^^^^^^\n\n");
		return (1);
	}
	if (is_sorted(arr_dst, size_dst))
	{
		puts("\n\n^^^^^^^^^Sorted b^^^^^^^^^\n\n"); // TODO transfer all elements from b to a, check if sorted asc/desced
		return (1);
	}
	is_small_to_big = (arr_src[0] > arr_src[1]);
	size_p = *size_pivot;
	while (size_src != 0)
	{
		if (is_included(pivot_arr, size_p, arr_src[0]))
		{
			push(arr_dst, &size_dst, arr_src, &size_src);
			continue;
		}
		pivot_arr[size_p++] = arr_src[0];
		pivot = arr_src[0];
		shift_left(arr_src, size_src);
		i = 1;
		while (!is_included(pivot_arr, size_p, arr_src[0]))
		{
			if (arr_src[0] > pivot && is_small_to_big)
			{
				push(arr_dst, &size_dst, arr_src, &size_src);
				continue;
			}else if (arr_src[0] < pivot && !is_small_to_big)
			{
				push(arr_dst, &size_dst, arr_src, &size_src);
				continue;
			}
			else
				i++;
			shift_left(arr_src, size_src);
		}
		j = i;
		while(i-- > 0)
			shift_right(arr_src, size_src);
		push(arr_dst, &size_dst, arr_src, &size_src);
	}
	*size_pivot = size_p;
	*size_d = size_dst;
	*size_s = size_src;
	return (0);
}
