/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:40 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:44:56 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (first->value > third->value)
			sa(stack, print);
		else
		{
			ra(stack, print);
			sa(stack, print);
			rra(stack, print);
		}
	}
	else
	{
		if (second->value < third->value)
			sa(stack, print);
		else
		{
			ra(stack, print);
			sa(stack, print);
		}
	}
}

// static void	sort_four(t_stack **a, t_stack **b, bool print)
// {
// 	t_elem	*min_node;

// 	min_node = stack_get_min(*a);
// 	while (*a != min_node)
// 		ra(a, print);
// 	pb(a, b, print);
// 	sort_three(a, print);
// 	pa(a, b, print);
// }

// static void	sort_five(t_stack **a, t_stack **b, bool print)
// {
// 	t_stack	*min_node;

// 	min_node = get_min(*a);
// 	while (*a != min_node)
// 		ra(a, print);
// 	pb(a, b, print);
// 	sort_four(a, b, print);
// 	pa(a, b, print);
// }

void	sort(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
		sa(a, true);
	else if (a->size == 3)
		sort_three(a, true);
	// else if (a->size == 4)
	// 	sort_four(a, b, true);
	// else if (a->size == 5)
	// 	sort_five(a, b, true);
	// else if (a->size <= MAX_SELECTION_NUMBER)
	// 	selection_sort(a, b, true);
	// else
	// 	radix_sort(a, b, true);
}