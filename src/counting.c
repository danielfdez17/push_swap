/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:39:00 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:48:23 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function counts the number of occurrences of every node
 * in @param stack and  * stores it in it's position in the 
 * array @param accumulates.
 * The @param min_value purpose is to generalize the storing process
 * @example stack: [1, -1], min_value = -1 --> accumulates = [1, 0, 1]
 */
static void	count_occurrences(t_stack *stack, int *accumulates, long min_value)
{
	t_elem	*ptr;

	ptr = stack->top;
	while (ptr)
	{
		accumulates[ptr->value - min_value]++;
		ptr = ptr->next;
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
static void	sort_values(t_elem *elem, int *sorted,
	int *accumulates, long min_value)
{
	t_elem	*ptr;

	ptr = elem;
	while (ptr)
	{
		sorted[accumulates[ptr->value - min_value] - 1] = ptr->value;
		ptr = ptr->next;
	}
}

int	*counting_sort(t_stack *stack)
{
	int			*accumulates;
	int			*sorted;
	t_elem		*min_elem;
	t_elem		*max_elem;

	min_elem = stack_get_min(stack);
	max_elem = stack_get_max(stack);
	accumulates = ft_calloc((max_elem->value - min_elem->value + 1),
			sizeof(int));
	if (!accumulates)
		return (NULL);
	sorted = ft_calloc(stack->size, sizeof(int));
	if (!sorted)
	{
		free(accumulates);
		return (NULL);
	}
	count_occurrences(stack, accumulates, min_elem->value);
	accumulate(accumulates, max_elem->value - min_elem->value);
	sort_values(stack->top, sorted, accumulates, min_elem->value);
	free(accumulates);
	return (sorted);
}
