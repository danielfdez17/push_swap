/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:49 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:50:03 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (size);
	while (stack)
	{
		stack = stack->next;
		++size;
	}
	return (size);
}

t_stack	*stack_new(int value)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	elem->index = 0;
	elem->previous = NULL;
	return (elem);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (TRUE);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
