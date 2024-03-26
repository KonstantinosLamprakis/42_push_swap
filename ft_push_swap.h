/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:03:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/26 03:21:32 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}		t_stacks;

// declarations for ft_push_swap_utils.c
void	ft_putstr(int fd, char *str);
int		is_sorted(int *arr, int size);
int		is_included(int *arr, int size, int value);
// declarations for stack_ops.c
void	push_a(t_stacks stacks, int *size_a, int *size_b);
void	push_b(t_stacks stacks, int *size_a, int *size_b);
void	shift_right(int *arr, int size, char c);
void	shift_left(int *arr, int size, char c);
void	swap(int *arr, int size, char c);
// declarations for validation.c
int		*is_valid(int argc, char *argv[]);
// declarations for ft_push_swap.c
void	print_array(int *arr, int size, char c);
// declarations for quicksort.c
// int	sort_stack(int *arr_src, int *size_s, int *arr_dst,
// int *size_d, int *pivot_arr, int *size_pivot);
// int	quicksort(int *arr_a, int size_a, int *arr_b, int size_b);
// declarations of radix.c
void	create_index(int **arr_a, int size_a);
#endif
