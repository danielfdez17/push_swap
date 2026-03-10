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

/**
 * Checks if the stack is sorted
 * @param stack The stack to check
 * @return true if the stack is sorted, false otherwise
 */
bool	is_stack_sorted(t_stack *stack);
/**
 * Creates a new element with the given value
 * @param value The value of the new element
 * @return A pointer to the new element
 */
t_elem	*new_elem(int value);
/**
 * Frees the memory allocated for the stack and its elements
 * @param stack The stack to free
 */
void	free_stack(t_stack *stack);
/**
 * Pushes an element to the bottom of the stack
 * @param stack The stack to push the element to
 * @param elem The element to push
 */
void	push_bottom(t_stack *stack, t_elem *elem);
/**
 * Pushes an element to the top of the stack
 * @param stack The stack to push the element to
 * @param elem The element to push
 */
void	push_top(t_stack *stack, t_elem *elem);
/**
 * Removes and returns the element at the top of the stack
 * @param stack The stack to pop the element from
 * @return The popped element, or NULL if the stack is empty
 */
t_elem	*pop_top(t_stack *stack);
/**
 * Removes and returns the element at the bottom of the stack
 * @param stack The stack to pop the element from
 * @return The popped element, or NULL if the stack is empty
 */
t_elem	*pop_bottom(t_stack *stack);
/**
 * Returns the maximum element in the stack
 * @param stack The stack to search
 * @return The maximum element, or NULL if the stack is empty
 */
t_elem	*stack_get_max(t_stack *stack);
/**
 * Returns the minimum element in the stack
 * @param stack The stack to search
 * @return The minimum element, or NULL if the stack is empty
 */
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