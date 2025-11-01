

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

typedef struct s_stack
{
	struct 	s_stack *previous;
	struct 	s_stack *next;
	int 	value;
	int		index;
} t_stack;

typedef struct s_value
{
	int	front;
	int	value;
	int	back;
} t_value;

#define A 'a'
#define B 'b'

// * SORTING ALGORITHMS
int	selection_sort(t_stack *a, t_stack *b);
int	radix_sort(t_stack **a, t_stack **b, int size);

// * LISTS
t_stack	*copy_list(t_stack *list);
void	print_node(t_stack *node);
void	print_list(t_stack *list, char stack);
t_stack	*list_new(int value);
t_stack	*list_last(t_stack *list);
void	free_list(t_stack *list);
void	push_back(t_stack **list, t_stack *elem);
void	push_front(t_stack **list, t_stack *elem);
t_stack	*pop_front(t_stack **list);

// * SWAP
void	swap_values(int *a, int *b);
// int		swap(t_stack *list);
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

// * PUSH
// int		push_from_to(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);

// * ROTATE
// int 	rotate(t_stack *list, char stack);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);

// * REVERSE ROTATE
// int		reverse_rotate(t_stack *list, char stack);
int		rrr(t_stack **a, t_stack **b);
int 	rra(t_stack **a);
int 	rrb(t_stack **b);

#endif