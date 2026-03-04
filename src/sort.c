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
static void	sort_three(t_stack **stack, bool print)
{
	t_stack	*max_node;

	max_node = get_max(*stack);
	if (max_node == *stack)
		ra(stack, print);
	else if ((*stack)->next == max_node)
		rra(stack, print);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, print);
}

static void	sort_four(t_stack **a, t_stack **b, bool print)
{
	t_stack	*min_node;

	min_node = get_min(*a);
	while (*a != min_node)
		ra(a, print);
	pb(a, b, print);
	sort_three(a, print);
	pa(a, b, print);
}

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

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a, true);
	else if (size == 3)
		sort_three(a, true);
	else if (size == 4)
		sort_four(a, b, true);
	// else if (size == 5)
	// 	sort_five(a, b, true);
	else if (size <= MAX_SELECTION_NUMBER)
		selection_sort(a, b, true);
	else
		radix_sort(a, b, size, true);
}