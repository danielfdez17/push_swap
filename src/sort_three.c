/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
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
void	sort_three(t_stack **stack, t_bool print)
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
