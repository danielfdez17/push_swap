

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct 	s_list *previous;
	struct 	s_list *next;
	int 	value;
} t_list;

typedef struct s_value
{
	int	from_begin;
	int	value;
	int	from_behind;
} t_value;

// * SORTING ALGORITHMS
int	selection_sort(t_list *a, t_list *b);
int	radix_sort(t_list *a, t_list *b);

// * LISTS
void	print_node(t_list *node);
void	print_list(t_list *list);
t_list	*list_new(int value);
t_list	*list_last(t_list *list);
void	free_list(t_list *list);
void	push_back(t_list **list, t_list *elem);
void	push_front(t_list **list, t_list *elem);
t_list	*pop_front(t_list **list);

// * SWAP
void	swap_values(int *a, int *b);
int		swap(t_list *list);
int		ss(t_list *a, t_list *b);

// * PUSH
int		push(t_list **a, t_list **b);

// * ROTATE
int 	rotate(t_list *list);
int		rr(t_list *a, t_list *b);

// * REVERSE ROTATE
int		reverse_rotate(t_list *list);
int		rrr(t_list *a, t_list *b);

#endif