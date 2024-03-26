/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:50:46 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 06:22:22 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_bits_num(int num);

void	radix(t_stacks *stacks)
{
	int	i;
	int	num_bits;
	int	j;

	num_bits = get_bits_num(stacks->a_size - 1);
	i = 0;
	while (i < num_bits && !is_sorted(stacks->a, stacks->a_size))
	{
		j = 0;
		while (j < stacks->a_size && !is_sorted(stacks->a, stacks->a_size))
		{
			if (((stacks->a[0] >> i) & 1) == 1)
				shift_left(stacks->a, stacks->a_size, 'a');
			else
			{
				push_b(*stacks);
				continue ;
			}
			j++;
		}
		while (stacks->b_size)
			push_a(*stacks);
		i++;
	}
}

static int	get_bits_num(int num)
{
	int	num_bits;
	int	i;

	num_bits = 1;
	i = num;
	while (i > 1)
	{
		num_bits++;
		i /= 2;
	}
	return (num_bits);
}
