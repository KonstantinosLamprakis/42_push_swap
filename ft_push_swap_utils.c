/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:04:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 12:00:06 by klamprak         ###   ########.fr       */
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

// returns 1 if array is sorted asceding or desceding, 0 otherwise
int	is_sorted(int *arr, int size)
{
	int	i;
	int	is_sorted;

	if (!arr || size < 1)
		return (0);
	if (size == 1)
		return (1);
	is_sorted = 1;
	i = 0;
	while (++i < size && is_sorted)
		if (arr[i] < arr[i - 1])
			is_sorted = 0;
	if (is_sorted)
		return (1);
	i = 0;
	is_sorted = 1;
	while (++i < size && is_sorted)
		if (arr[i] > arr[i - 1])
			is_sorted = 0;
	return (is_sorted);
}

// returns 1 if value is included on arr, 0 otherwise
int	is_included(int *arr, int size, int value)
{
	int	i;

	if (!arr || size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}
