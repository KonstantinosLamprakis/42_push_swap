/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:53:42 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/25 09:32:28 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_int(char *str, int *result);
static int	has_daplicates(int *args, int size);
static long	ft_atoi(const char *str);
static long	get_int(const char *str, int i, int sign);

// checks if initial args are valid and print error if not on stderror(fd 2)
// returns 1 if are valid, 0 otherwise
// error means not integer value, overflow-underflow, duplicates, 0 args
int	*is_valid(int argc, char *argv[])
{
	int	i;
	int	*args_arr;

	args_arr = malloc((argc - 1) * sizeof(int));
	if (!args_arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i], &args_arr[i - 1]))
		{
			ft_putstr(2, "Error\n");
			free(args_arr);
			return (NULL);
		}
		i++;
	}
	if (has_daplicates(args_arr, argc - 1))
	{
		ft_putstr(2, "Error\n");
		free(args_arr);
		return (NULL);
	}
	return (args_arr);
}

// insteger means less than 10 digits + 1 for sign
// checks also for overflow, underflow 2147483647 -2147483648
// checks if exist characters other than digits
// returns 1 if number is integer or 0 if not
// puts the result number on &result
static int	is_int(char *str, int *result)
{
	int		i;
	long	temp;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i > 11 || i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+')))
		return (0);
	temp = ft_atoi(str);
	if (temp > 2147483647 || temp < -2147483648)
		return (0);
	*result = (int) temp;
	return (1);
}

// args: a list with integer to check for duplicates
// size: the size of the list
// returns 1 if args has duplicate int or 0 otherwise
static int	has_daplicates(int *args, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (args[i] == args[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (get_int(str, i, sign));
}

static long	get_int(const char *str, int i, int sign)
{
	long	div;
	long	result;
	int		end;

	result = 0;
	end = i;
	while (str[end] != '\0' && str[end] >= '0' && str[end] <= '9')
		end++;
	div = 1;
	if (end == 0)
		return (0);
	while (str[end - 1] >= '0' && str[end - 1] <= '9')
	{
		result = result - ((str[end - 1] - '0') * div);
		div *= 10;
		if (end == 1)
			break ;
		end--;
	}
	return (result * sign * -1);
}
