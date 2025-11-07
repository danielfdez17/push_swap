/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:39:00 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:41:17 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/push_swap.h"

/**
 * Receives a @param stack and @returns a structure containing
 * both min and max values in the stack
 */
static t_limits	get_limits(t_stack *stack)
{
	t_limits	limits;

	limits.max = stack->value;
	limits.min = stack->value;
	while (stack)
	{
		if (stack->value > limits.max)
			limits.max = stack->value;
		else if (stack->value < limits.min)
			limits.min = stack->value;
		stack = stack->next;
	}
	return (limits);
}

/**
 * The function counts the number of occurrences of every node
 * in @param stack and  * stores it in it's position in the 
 * array @param accumulates.
 * The @param min_value purpose is to generalize the storing process
 * @example stack: [1, -1], min_value = -1 --> accumulates = [1, 0, 1]
 */
static void	count_occurrences(t_stack *stack, int *accumulates, long min_value)
{
	while (stack)
	{
		accumulates[stack->value - min_value]++;
		stack = stack->next;
	}
}

/**
 * The function accumulates, (in @param accumulates) the number
 * of occurrences for every node in @param stack calculated
 * in previous function to know the sorted position for every
 * node in @param stack.
 * @param size indicates the total size of @param accumulates - 1
 * because each iteration is processing two elements at a time
 * @example: stack: [1, -1], size = 2, accumulates = [1, 0, 1] 
 * --> accumulates = [1, 1, 2]
 */
static void	accumulate(int *accumulates, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		accumulates[i + 1] += accumulates[i];
		++i;
	}
}

/**
 * The function sorts in ascending order the values stored
 * in @param stack in the @param sorted array.
 * @param accumulates indicates the correct position for every node
 * in @param stack to be stored in @param sorted.
 * @param min_value helps to generalize the sorting process
 * @example: stack = [1, -1], accumulates = [1, 1, 2], min_value = -1
 * --> sorted = [-1, 1]
 */
static void	sort_values(t_stack *stack, int *sorted, \
	int *accumulates, long min_value)
{
	while (stack)
	{
		sorted[accumulates[stack->value - min_value] - 1] = stack->value;
		stack = stack->next;
	}
}

/**
 * @returns the sorted array of the values of @param stack
 * using previous functions.
 */
int	*counting_sort(t_stack *stack)
{
	int			*accumulates;
	int			*sorted;
	t_limits	limits;

	limits = get_limits(stack);
	accumulates = malloc(sizeof(int) * (limits.max - limits.min + 1));
	if (!accumulates)
		return (NULL);
	sorted = malloc(sizeof(int) * get_size(stack));
	if (!sorted)
		return (NULL);
	ft_bzero(accumulates, limits.max - limits.min + 1);
	count_occurrences(stack, accumulates, limits.min);
	accumulate(accumulates, limits.max - limits.min);
	sort_values(stack, sorted, accumulates, limits.min);
	free(accumulates);
	return (sorted);
}
