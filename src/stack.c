

#include "../inc/headers/push_swap.h"


void	print_node(t_stack *node)
{
	ft_printf("(%d,%d) ", node->value, node->index);
}

void print_list(t_stack *stack)
{
	while (stack)
	{
		print_node(stack);
		stack = stack->next;
	}
	ft_printf("\n");
}

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

t_stack *list_new(int value)
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

void push_back(t_stack **stack, t_stack *elem)
{
	t_stack *ptr;

	ptr = stack_last(*stack);
	if (!ptr)
		*stack = elem;
	else
	{
		elem->previous = ptr;
		ptr->next = elem;
	}
}

t_stack	*copy_list(t_stack *stack)
{
	t_stack *new_elem;
	t_stack *new_list;

	new_list = NULL;
	while (stack)
	{
		new_elem = list_new(stack->value);
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