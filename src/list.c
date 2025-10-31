

#include "../inc/headers/push_swap.h"


void print_node(t_list *node)
{
	printf("prev: %d ", node->previous ? node->previous->value : -1);
	printf(" <-> value: %d ", node->value);
	printf("next: %d\n", node->next ? node->next->value : -1);
}

void print_list(t_list *list, char stack)
{
	printf("%c: ", stack);
	while (list)
	{
		// print_node(list);
		printf("(%d) ", list->value);
		list = list->next;
	}
	printf("\n");
}

t_list *list_new(int value)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	// Defensive: ensure the popped node is fully detached from the list
	elem->previous = NULL;
	return (elem);
}

t_list *list_last(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void free_list(t_list *list)
{
	t_list *ptr;

	while (list)
	{
		ptr = list;
		list = list->next;
		free(ptr);
	}
}

void	push_front(t_list **list, t_list *elem)
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

t_list	*pop_front(t_list **list)
{
	t_list 	*elem;

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

void push_back(t_list **list, t_list *elem)
{
	t_list *ptr;

	ptr = list_last(*list);
	if (!ptr)
		*list = elem;
	else
	{
		elem->previous = ptr;
		ptr->next = elem;
	}
}

t_list	*copy_list(t_list *list)
{
	t_list *new_elem;
	t_list *new_list;

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