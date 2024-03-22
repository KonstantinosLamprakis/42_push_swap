/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:39:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 11:50:45 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// swaps first 2 elements of table
void	swap(int *arr, int size)
{
	int	temp;

	if (!arr || size < 2)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

// shifts the whole table 1 place to the left
// 1st element become now last
void	shift_left(int *arr, int size)
{
	int	i;
	int	temp;

	if (!arr || size < 2)
		return ;
	temp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
}

// shifts the whole table 1 place to the right
// last element becomes now 1st
void	shift_right(int *arr, int size)
{
	int	i;
	int	temp;

	i = size - 1;
	if (!arr || size < 2)
		return ;
	temp = arr[size - 1];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
}

// removes 1st elemet of arr_src and put it as 1st element at arr_dst
// all other element of dst go one place left
void	push(int *arr_dst, int *size_dst, int *arr_src, int *size_src)
{
	int	i;

	if (!arr_dst || !arr_src || *size_src < 1)
		return ;
	i = *size_dst;
	while (i > 0)
	{
		arr_dst[i] = arr_dst[i - 1];
		i--;
	}
	arr_dst[0] = arr_src[0];
	i = 0;
	while (i < *size_src - 1)
	{
		arr_src[i] = arr_src[i + 1];
		i++;
	}
	arr_src[*size_src - 1] = -1;
	(*size_dst)++;
	(*size_src)--;
}
