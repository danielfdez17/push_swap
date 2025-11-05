

#include "../inc/headers/push_swap.h"

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

t_stack *stack_new(int value)
{
	t_stack *elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	elem->index = 0;
	elem->previous = NULL;
	return (elem);
}

t_stack *stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
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

void free_stack(t_stack *stack)
{
	t_stack *ptr;

	while (stack)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
	stack = NULL;
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
	}
	else
	{
		elem->next = *stack;
		elem->previous = NULL;
		(*stack)->previous = elem;
		*stack = elem;
	}
}

/*
 * Removes and returns the first element from the stack.
 * Parameters:
 *   stack - double pointer to the head of the stack.
 * Returns:
 *   Pointer to the removed element, or NULL if the stack is empty.
 */
t_stack	*pop_front(t_stack **stack)
{
	t_stack 	*elem;

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

/*
 * Adds an element to the end of the stack.
 * Parameters:
 *   stack - double pointer to the head of the stack.
 *   elem  - pointer to the element to be added.
 * Returns:
 *   None.
 */
void push_back(t_stack **stack, t_stack *elem)
{
	t_stack *last;

	last = stack_last(*stack);
	if (!last)
		*stack = elem;
	else
	{
		elem->previous = last;
		elem->next = NULL;
		last->next = elem;
	}
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

t_stack	*copy_stack(t_stack *stack)
{
	t_stack *new_elem;
	t_stack *new_list;

	new_list = NULL;
	while (stack)
	{
		new_elem = stack_new(stack->value);
		if (!new_elem)
		{
			free_stack(new_list);
			return (NULL);
		}
		push_back(&new_list, new_elem);
		stack = stack->next;
	}

	return (new_list);
}