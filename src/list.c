

#include "../inc/headers/push_swap.h"


void print_node(t_stack *node)
{
	ft_printf("(%d,%d) ", node->value, node->index);
}

void print_list(t_stack *list, char stack)
{
	ft_printf("%c: ", stack);
	while (list)
	{
		print_node(list);
		// ft_printf("(%d) ", list->value);
		list = list->next;
	}
	ft_printf("\n");
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

t_stack *list_last(t_stack *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void free_list(t_stack *list)
{
	t_stack *ptr;

	while (list)
	{
		ptr = list;
		list = list->next;
		free(ptr);
	}
	list = NULL;
}

void	push_front(t_stack **list, t_stack *elem)
{
	if (!elem)
		return ;
	if (!*list)
	{
		elem->previous = NULL;
		*list = elem;
		if ((*list)->next)
			elem->next = (*list)->next;
		else
			elem->next = NULL;
	}
	else
	{
		elem->next = *list;
		elem->previous = NULL;
		(*list)->previous = elem;
		*list = elem;
	}
}

t_stack	*pop_front(t_stack **list)
{
	t_stack 	*elem;

	if (!list || !*list)
		return (NULL);
	elem = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->previous = NULL;
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}

void push_back(t_stack **list, t_stack *elem)
{
	t_stack *ptr;

	ptr = list_last(*list);
	if (!ptr)
		*list = elem;
	else
	{
		elem->previous = ptr;
		ptr->next = elem;
	}
}

t_stack	*copy_list(t_stack *list)
{
	t_stack *new_elem;
	t_stack *new_list;

	new_list = NULL;
	while (list)
	{
		new_elem = list_new(list->value);
		if (!new_elem)
		{
			free_list(new_list);
			return (NULL);
		}
		push_back(&new_list, new_elem);
		list = list->next;
	}

	return (new_list);
}