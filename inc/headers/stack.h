#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*next;
	struct s_elem	*prev;
	int				position;
	int				front;
	int				back;
}	t_elem;

typedef struct s_stack
{
	int		size;
	t_elem	*top;
	t_elem	*bottom;
}	t_stack;

typedef struct	s_best_move
{
	t_elem	*elem;
	int		current_a;
	int		current_b;
	int		best_total;
	int		total;
}	t_best_move;

bool	is_stack_sorted(t_stack *stack);
t_elem	*new_elem(int value);
void	free_stack(t_stack *stack);
void	push_bottom(t_stack *stack, t_elem *elem);
void	push_top(t_stack *stack, t_elem *elem);
t_elem	*pop_top(t_stack *stack);
t_elem	*pop_bottom(t_stack *stack);
t_elem	*stack_get_max(t_stack *stack);
t_elem	*stack_get_min(t_stack *stack);

/**
 * Prints the elements of the stack
 * @brief Prints the elements of the stack
 * @param stack The stack to print
 */
void	print_stack(t_stack *stack);

static inline void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

static inline int	stack_size(t_stack *stack)
{
	if (!stack)
		return (-1);
	return (stack->size);
}

static inline bool	is_stack_empty(t_stack *stack)
{
	if (!stack)
		return (true);
	return (stack->size == 0);
}

static inline t_elem	*stack_top(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->top);
}
static inline t_elem	*stack_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->bottom);
}

#endif // STACK_H