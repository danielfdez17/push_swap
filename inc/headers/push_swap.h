

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	struct 	s_list *previous;
	struct 	s_list *next;
	int 	value;
	int		index;
} t_list;

typedef struct s_value
{
	int	front;
	int	value;
	int	back;
} t_value;

#define A 'a'
#define B 'b'

// * SORTING ALGORITHMS
int	selection_sort(t_list *a, t_list *b);
int	radix_sort(t_list **a, t_list **b, int size);

// * LISTS
t_list	*copy_list(t_list *list);
void	print_node(t_list *node);
void	print_list(t_list *list, char stack);
t_list	*list_new(int value);
t_list	*list_last(t_list *list);
void	free_list(t_list *list);
void	push_back(t_list **list, t_list *elem);
void	push_front(t_list **list, t_list *elem);
t_list	*pop_front(t_list **list);

// * SWAP
void	swap_values(int *a, int *b);
// int		swap(t_list *list);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

// * PUSH
// int		push_from_to(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

// * ROTATE
// int 	rotate(t_list *list, char stack);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

// * REVERSE ROTATE
// int		reverse_rotate(t_list *list, char stack);
int		rrr(t_list **a, t_list **b);
int 	rra(t_list **a);
int 	rrb(t_list **b);

#endif