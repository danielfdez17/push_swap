/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:49 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:39:09 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_stack *stack)
{
	t_elem	*ptr;

	if (is_stack_empty(stack))
		return (true);
	ptr = stack->top->next;
	while (ptr)
	{
		if (ptr->prev->value > ptr->value)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}

t_elem	*new_elem(int value)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->index = -1;
	elem->next = NULL;
	elem->prev = NULL;
	elem->position = -1;
	elem->front = 0;
	elem->back = 0;
	return (elem);
}

void	free_stack(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*prev_ptr;

	if (!stack)
		return ;
	ptr = stack->top;
	while (ptr)
	{
		prev_ptr = ptr;
		ptr = ptr->next;
		free(prev_ptr);
	}
	stack = NULL;
}

t_elem	*stack_get_max(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*max;

	if (!stack || is_stack_empty(stack))
		return (NULL);
	ptr = stack->top;
	max = ptr;
	while (ptr)
	{
		if (ptr->value > max->value)
			max = ptr;
		ptr = ptr->next;
	}
	return (max);
}

t_elem	*stack_get_min(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*min;

	if (!stack || is_stack_empty(stack))
		return (NULL);
	ptr = stack->top;
	min = ptr;
	while (ptr)
	{
		if (ptr->value < min->value)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}
