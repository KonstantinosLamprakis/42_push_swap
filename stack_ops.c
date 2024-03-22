/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:39:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 09:40:19 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// swaps first 2 elements of table
void	swap(int *arr, int size)
{
	int	temp;
	int	actual_size;

	actual_size = get_actual_size(arr, size);
	if (actual_size < size)
		size = actual_size;
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
	int	actual_size;

	actual_size = get_actual_size(arr, size);
	if (actual_size < size)
		size = actual_size;
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
	int	actual_size;

	actual_size = get_actual_size(arr, size);
	if (actual_size < size)
		size = actual_size;
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
void	push_table(int *arr_dst, int size_dst, int *arr_src, int size_src)
{
	int	i;
	int	actual_size;

	actual_size = get_actual_size(arr_dst, size_dst);
	if (actual_size < size_dst)
		size_dst = actual_size;
	actual_size = get_actual_size(arr_src, size_src);
	if (actual_size < size_src)
		size_src = actual_size;
	if (!arr_dst || !arr_src || size_src < 1)
		return ;
	i = size_dst;
	while (i > 0)
	{
		arr_dst[i] = arr_dst[i - 1];
		i--;
	}
	arr_dst[0] = arr_src[0];
	i = 0;
	while (i < size_src - 1)
	{
		arr_src[i] = arr_src[i + 1];
		i++;
	}
	arr_src[size_src - 1] = -1;
}
