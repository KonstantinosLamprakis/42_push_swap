/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:04:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 09:58:06 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// prints a string str
void	ft_putstr(int fd, char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], sizeof(char));
		i++;
	}
}

// get the actual size of an array
// max_size is the maximum size, the space that is allocated
// actual size is the number of positive numbers in the array
// -1 means an empty cell, so we stop when we find the 1st empty cell
int	get_actual_size(int *arr, int max_size)
{
	int	i;

	if (!arr || max_size < 1)
		return (0);
	i = 0;
	while (i < max_size)
	{
		if (arr[i] == -1)
			return (i);
		i++;
	}
	return (i);
}

// allocates memory for new table of ints, fill it with -1 and returns it
int	*init(int size)
{
	int	*arr;
	int	i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = -1;
		i++;
	}
	return (arr);
}
