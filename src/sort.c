/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:40 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:46:49 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_in_the_middle(t_stack *stack,
	t_elem *first, t_elem *third, bool print)
{
	if (first->value > third->value)
		rra(stack, print);
	else
	{
		ra(stack, print);
		sa(stack, print);
		rra(stack, print);
	}
}

/**
 * Algorithm to sort only 3 elements
 */
static void	sort_three(t_stack *stack, bool print)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;
	t_elem	*max;

	first = stack->top;
	second = first->next;
	third = second->next;
	max = stack_get_max(stack);
	if (third == max)
		sa(stack, print);
	else if (second == max)
		max_in_the_middle(stack, first, third, print);
	else
	{
		if (second->value < third->value)
			ra(stack, print);
		else
		{
			ra(stack, print);
			sa(stack, print);
		}
	}
}

static void	sort_four(t_stack *a, t_stack *b, bool print)
{
	while (a->size != 3)
		push_min_to_b(a, b, print);
	if (!is_stack_sorted(a))
		sort_three(a, print);
	pa(a, b, print);
}

void	sort(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
		sa(a, true);
	else if (a->size == 3)
		sort_three(a, true);
	else if (a->size == 4)
		sort_four(a, b, true);
	else
		bucket_sort(a, b, true);
}
