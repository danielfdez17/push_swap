

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

# define A 'a'
# define B 'b'
# define RR 1
# define RRR -1

typedef int t_bool;

typedef struct s_stack
{
	struct 	s_stack *previous;
	struct 	s_stack *next;
	struct 	s_stack *target;
	int 	value;
	int		index;
	int		push_cost;
	t_bool	above_median;
	t_bool	cheapest;
} t_stack;

typedef struct s_value
{
	int	front;
	int	value;
	int	back;
} t_value;

// * ERROR HANDLING
t_bool	syntax_error(char *s);
t_bool	duplicate_error(t_stack *stack, int n);
void	free_error(t_stack **stack);

// * SORTING ALGORITHMS
int	selection_sort(t_stack *a, t_stack *b);
int		radix_sort(t_stack **a, t_stack **b, int size);
void	turk_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);

// * STACKS
void	init_stack(t_stack **a, char **av);
void	init_a(t_stack *a, t_stack *b);
void	init_b(t_stack *a, t_stack *b);
void	set_indexes(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *node, char stack_name);
int		get_size(t_stack *stack);
// t_stack	*stack_last(t_stack *stack);
t_bool	is_stack_sorted(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_max(t_stack *stack);

t_stack	*copy_list(t_stack *list);
void	print_node(t_stack *node);
void	print_list(t_stack *list);
t_stack	*list_new(int value);
t_stack	*stack_last(t_stack *list);
void	free_stack(t_stack *list);
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