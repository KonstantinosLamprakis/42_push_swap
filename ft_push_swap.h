/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:03:05 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/22 11:37:57 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// declarations for ft_push_swap_utils.c
void	ft_putstr(int fd, char *str);
int		*init(int size);
int		get_actual_size(int *arr, int max_size);
int		is_sorted(int *arr, int size);
int		is_included(int *arr, int size, int value);
// declarations for stack_ops.c
void	push(int *arr_dst, int size_dst, int *arr_src, int size_src);
void	shift_right(int *arr, int size);
void	shift_left(int *arr, int size);
void	swap(int *arr, int size);
// declarations for validation.c
int		*is_valid(int argc, char *argv[]);
#endif
