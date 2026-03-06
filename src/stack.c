/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:14 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 17:09:55 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *stack, t_elem *elem)
{
	if (!elem)
		return ;
	if (is_stack_empty(stack))
	{
		(stack)->top = elem;
		(stack)->bottom = elem;
	}
	else
	{
		(stack)->bottom->next = elem;
		elem->prev = (stack)->bottom;
		(stack)->bottom = elem;
	}
	elem->position = stack->size;
	elem->front = elem->position;
	elem->back = stack->size - elem->position;
	(stack)->size++;
}

void	push_top(t_stack *stack, t_elem *elem)
{
	if (!elem)
		return ;
	if (is_stack_empty(stack))
	{
		(stack)->top = elem;
		(stack)->bottom = elem;
	}
	else
	{
		(stack)->top->prev = elem;
		elem->next = (stack)->top;
		(stack)->top = elem;
	}
	(stack)->size++;
}

t_elem	*pop_bottom(t_stack *stack)
{
	t_elem	*elem;

	if ((stack)->size <= 0)
		return (NULL);
	if ((stack)->size == 1)
	{
		elem = (stack)->bottom;
		elem->next = NULL;
		elem->prev = NULL;
		(stack)->bottom = NULL;
		(stack)->top = NULL;
	}
	else
	{
		elem = (stack)->bottom;
		(stack)->bottom = elem->prev;
		(stack)->bottom->next = NULL;
		elem->next = NULL;
		elem->prev = NULL;
	}
	(stack)->size--;
	return (elem);
}

t_elem	*pop_top(t_stack *stack)
{
	t_elem	*elem;

	if ((stack)->size <= 0)
		return (NULL);
	if ((stack)->size == 1)
	{
		elem = (stack)->top;
		elem->next = NULL;
		elem->prev = NULL;
		(stack)->bottom = NULL;
		(stack)->top = NULL;
	}
	else
	{
		elem = (stack)->top;
		(stack)->top = elem->next;
		(stack)->top->prev = NULL;
		elem->next = NULL;
		elem->prev = NULL;
	}
	(stack)->size--;
	return (elem);
}

void	print_stack(t_stack *stack)
{
	t_elem	*ptr;

	ptr = stack->top;
	ft_printf("(value, index)\n");
	while (ptr)
	{
		ft_printf("(%d,%d) ", ptr->value, ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
}
