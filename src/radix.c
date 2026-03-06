/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:52 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:23:35 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Assigns an index to each node of @param stack using counting sort algorithm.
 * @example: stack = [-2, 5, 3, 0] --> index of each value = [0, 3, 2, 1]
 */
void	set_indexes(t_stack *stack)
{
	int		*sorted;
	int		i;
	t_elem	*ptr;

	i = 0;
	sorted = counting_sort(stack);
	while (i < stack->size)
	{
		ptr = stack->top;
		while (ptr)
		{
			if (ptr->value == sorted[i])
			{
				ptr->index = i;
				break ;
			}
			ptr = ptr->next;
		}
		++i;
	}
	free(sorted);
}

/**
 * Auxiliary function to reduce number of lines
 */
static void	radix_aux(t_stack *a, t_stack *b, int i, bool print)
{
	int	index;

	index = a->top->index;
	if (((index >> i) & 1) == 0)
		pb(a, b, print);
	else
		ra(a, print);
}

/**
 * Binary radix sort implementation
 */
void	radix_sort(t_stack *a, t_stack *b, bool print)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;

	max_bits = 0;
	max_num = a->size - 1;
	set_indexes(a);
	while (max_num >> max_bits)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		while (++j < a->size)
			radix_aux(a, b, i, print);
		while (b->top)
			pa(a, b, print);
		++i;
	}
}
