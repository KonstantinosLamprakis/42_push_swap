/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:50:46 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 03:22:21 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
