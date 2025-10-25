

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list *previous;
	struct s_list *next;
	int value;
} t_list;

void print_node(t_list *node)
{
	printf("prev: %d ", node->previous ? node->previous->value : -1);
	printf("value: %d ", node->value);
	printf("next: %d\n", node->next ? node->next->value : -1);
}

void print_list(t_list *list)
{
	while (list)
	{
		// print_node(list);
		printf("(%d) ", list->value);
		list = list->next;
	}
	printf("\n");
}

void a(t_list *list)
{
	printf("\n%s: ", __func__);
	print_list(list);
}

void b(t_list *list)
{
	printf("\n%s: ", __func__);
	print_list(list);
}

t_list *list_new(int value)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
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

void push_back(t_list **list, int value)
{
	t_list *elem;
	t_list *ptr;

	elem = list_new(value);
	if (!elem)
		return;
	if (!*list)
		*list = elem;
	else
	{
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		elem->previous = ptr;
		(ptr)->next = elem;
	}
}

void push_front(t_list **list, t_list *elem)
{
	if (!elem)
		return;
	if (!*list)
		*list = elem;
	else
	{
		elem->next = *list;
		(*list)->previous = elem;
		*list = elem;
	}
}

t_list *pop_front(t_list **list)
{
	t_list *elem;

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

void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int swap(t_list *list)
{
	if (list && list->next)
		swap_values(&list->value, &list->next->value);
	return (1);
}

int swap_swap(t_list *a, t_list *b)
{
	return (swap(a) + swap(b));
}

int push(t_list **a, t_list **b)
{
	if (!*b)
		return (0);
	push_front(a, (*b));
	pop_front(b);
	return (1);
}

int rotate(t_list *list)
{
	if (!list)
		return (0);
	while (list && list->next)
	{
		swap_values(&list->value, &list->next->value);
		list = list->next;
	}
	return (1);
}

int reverse_rotate(t_list *list)
{
	t_list *last;

	if (!list)
		return (0);
	last = list_last(list);
	while (last && last->previous)
	{
		swap_values(&last->value, &last->previous->value);
		last = last->previous;
	}
	return (1);
}

int rotate_rotate(t_list *a, t_list *b)
{
	return (rotate(a) + rotate(b));
}

int reverse_rotate_rotate(t_list *a, t_list *b)
{
	return (reverse_rotate(a) + reverse_rotate(b));
}

#endif