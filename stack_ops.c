/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:39:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 03:17:40 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// swaps first 2 elements of table
void	swap(int *arr, int size, char c)
{
	int	temp;

	if (!arr || size < 2)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

// shifts the whole table 1 place to the left
// 1st element become now last
void	shift_left(int *arr, int size, char c)
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
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

// shifts the whole table 1 place to the right
// last element becomes now 1st
void	shift_right(int *arr, int size, char c)
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
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

// removes 1st elemet of arr_b and put it as 1st element at arr_a
// all other element of dst go one place left
void	push_a(t_stacks stacks, int *size_a, int *size_b)
{
	int	i;

	if (!stacks.a || !stacks.b || stacks.b_size < 1)
		return ;
	i = stacks.a_size;
	while (i > 0)
	{
		stacks.a[i] = stacks.a[i - 1];
		i--;
	}
	stacks.a[0] = stacks.b[0];
	i = 0;
	while (i < stacks.b_size - 1)
	{
		stacks.b[i] = stacks.b[i + 1];
		i++;
	}
	stacks.b[stacks.b_size - 1] = -1;
	(*size_a)++;
	(*size_b)--;
	write(1, "pa\n", 3);
}

// removes 1st elemet of arr_a and put it as 1st element at arr_b
// all other element of dst go one place left
void	push_b(t_stacks stacks, int *size_a, int *size_b)
{
	int	i;

	if (!stacks.a || !stacks.b || stacks.a_size < 1)
		return ;
	i = stacks.b_size;
	while (i > 0)
	{
		stacks.b[i] = stacks.b[i - 1];
		i--;
	}
	stacks.b[0] = stacks.a[0];
	i = 0;
	while (i < stacks.a_size - 1)
	{
		stacks.a[i] = stacks.a[i + 1];
		i++;
	}
	stacks.a[stacks.a_size - 1] = -1;
	(*size_a)--;
	(*size_b)++;
	write(1, "pb\n", 3);
}
