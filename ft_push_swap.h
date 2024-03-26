/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:03:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 06:23:31 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int	*a_size_ptr;
	int	*b_size_ptr;
}		t_stacks;

// declarations for ft_push_swap_utils.c
void	ft_putstr(int fd, char *str);
int		is_sorted(int *arr, int size);
int		is_included(int *arr, int size, int value);
// declarations for stack_ops.c
void	push_a(t_stacks stacks);
void	push_b(t_stacks stacks);
void	shift_right(int *arr, int size, char c);
void	shift_left(int *arr, int size, char c);
void	swap(int *arr, int size, char c);
// declarations for validation.c
int		*is_valid(int argc, char *argv[]);
// declarations of radix.c
void	radix(t_stacks *stacks);
// declarations of radix_utils.c
int		sort_less_than_5(t_stacks *stacks);
void	create_index(int **arr_a, int size_a);
#endif
