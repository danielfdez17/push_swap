

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

typedef int t_bool;

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

// * SORTING ALGORITHMS
int	selection_sort(t_stack *a, t_stack *b);
int	radix_sort(t_stack **a, t_stack **b, int size);

// * LISTS
t_stack	*copy_list(t_stack *list);
void	print_node(t_stack *node);
void	print_list(t_stack *list);
t_stack	*list_new(int value);
t_stack	*list_last(t_stack *list);
void	free_list(t_stack *list);
void	push_back(t_stack **list, t_stack *elem);
void	push_front(t_stack **list, t_stack *elem);
t_stack	*pop_front(t_stack **list);

// * SWAP
void	swap_values(int *a, int *b);
int		sa(t_stack **a, t_bool print);
int		sb(t_stack **b, t_bool print);
int		ss(t_stack **a, t_stack **b, t_bool print);

// * PUSH
int		pa(t_stack **a, t_stack **b, t_bool print);
int		pb(t_stack **a, t_stack **b, t_bool print);

// * ROTATE
int		ra(t_stack **a, t_bool print);
int		rb(t_stack **b, t_bool print);
int		rr(t_stack **a, t_stack **b, t_bool print);

// * REVERSE ROTATE
int		rrr(t_stack **a, t_stack **b, t_bool print);
int 	rra(t_stack **a, t_bool print);
int 	rrb(t_stack **b, t_bool print);

#endif