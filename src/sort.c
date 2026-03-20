/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:40 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/20 16:57:10 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Handles the case where the maximum element is in the middle of the stack
 * and the first element is greater than the third element. It performs a reverse
 * rotate on the stack. Otherwise, it performs a rotate, a swap,
 * and then a reverse rotate to sort the three elements correctly.
 * @param stack The stack to be sorted.
 * @param first The first element of the stack.
 * @param third The third element of the stack.
 * @param print A boolean indicating whether to print the operations performed.
 */
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
 * The function first retrieves the first, second, and third elements
 * of the stack, as well as the maximum element.
 * It then checks the position of the maximum element and performs
 * the necessary operations (swap, rotate, reverse rotate)
 * to sort the three elements in the correct order.
 * The operations are performed based on the
 * relative values of the first, second, and third elements.
 * @param stack The stack to be sorted.
 * @param print A boolean indicating whether to print the operations performed.
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

/**
 * Algorithm to sort 4 elements
 * @param a The first stack to be sorted.
 * @param b The second stack used for sorting.
 * @param print A boolean indicating whether to print the operations performed.
 */
static void	sort_four(t_stack *a, t_stack *b, bool print)
{
	while (a->size != 3)
		push_min_to_b(a, b, print);
	if (!is_stack_sorted(a))
		sort_three(a, print);
	pa(a, b, print);
}

/**
 * Algorithm to sort 5 elements
 * @param a The first stack to be sorted.
 * @param b The second stack used for sorting.
 * @param print A boolean indicating whether to print the operations performed.
 */
static void	sort_five(t_stack *a, t_stack *b, bool print)
{
	while (a->size > 3)
		push_min_to_b(a, b, print);
	if (!is_stack_sorted(a))
		sort_three(a, print);
	while (!is_stack_empty(b))
		pa(a, b, print);
}

/**
 * Main sorting function
 * @param a The first stack to be sorted.
 * @param b The second stack used for sorting.
 */
void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a, true);
	else if (a->size == 3)
		sort_three(a, true);
	else if (a->size == 4)
		sort_four(a, b, true);
	else if (a->size == 5)
		sort_five(a, b, true);
	else
		sort_algorithm(a, b, true);
}
