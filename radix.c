/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:50:46 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/25 09:24:55 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// returns a new array, each element corresponds to the element with same index in arr_a
// it holds the position of this element in the sorted array
// if we sort the new array, its same as if we sort the initial one
// we do it to "convert" each value of arr_a to positive
// ex. arr_a = {-5 , 3, 0, -8, 6} -> result = {1, 3, 2, 0, 4}
// explain: -8 -> 0, -5 -> 1, 0 -> 2, 3 -> 3, 6 -> 4
int	*create_index(int *arr_a, int size_a)
{
	int	i;
	int	*result;
	int	j;

	if (!arr_a || size_a == 0)
		return (NULL);
	result = malloc(sizeof(int) * size_a);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size_a)
	{
		j = 0;
		result[i] = 0;
		while (j < size_a)
		{
			if (arr_a[j] < arr_a[i])
				result[i]++;
			j++;
		}
		i++;
	}
	return (result);
}
