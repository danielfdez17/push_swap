/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:38:01 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:45:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}
	*stack = NULL;
}

void	push_front(t_stack **stack, t_stack *elem)
{
	if (!elem)
		return ;
	if (!*stack)
	{
		elem->previous = NULL;
		*stack = elem;
		if ((*stack)->next)
			elem->next = (*stack)->next;
		else
			elem->next = NULL;
		return ;
	}
	elem->next = *stack;
	elem->previous = NULL;
	(*stack)->previous = elem;
	*stack = elem;
}

t_stack	*pop_front(t_stack **stack)
{
	t_stack	*elem;

	if (!stack || !*stack)
		return (NULL);
	elem = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->previous = NULL;
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}

void	push_back(t_stack **stack, t_stack *elem)
{
	t_stack	*last;

	last = stack_last(*stack);
	if (!last)
	{
		*stack = elem;
		return ;
	}
	elem->previous = last;
	elem->next = NULL;
	last->next = elem;
}

t_stack	*pop_back(t_stack **stack)
{
	t_stack	*last;

	last = stack_last(*stack);
	if (!last)
		return (NULL);
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	return (last);
}
