/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:31 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/13 07:44:54 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"

# ifndef DEBUG_MODE
#  define DEBUG_MODE false
# endif

# ifndef SORT_ALGO
#  define SORT_ALGO 0
# endif

# ifndef DEFAULT_CHUNK_SIZE
#  define DEFAULT_CHUNK_SIZE 70
# endif

// * ARGUMENTS PROCESSING
/**
 * Processes the command line arguments and fills the stack with the values
 * @param ac The number of arguments
 * @param av The arguments
 * @param a The stack to fill with the values
 * @returns true if the arguments are valid and the stack is filled,
 * false otherwise
 */
bool	process_arguments(int ac, char **av, t_stack *a);

// * ERROR HANDLING
/**
 * Checks if the input is valid (only digits, optional sign at the beginning,
 * and within the range of int)
 * @param s The string to check
 * @returns true if the input is valid, false otherwise
 */
bool	input_error(char *s);

// * SORTING ALGORITHMS
/**
 * Sorts the stack using the appropriate algorithm based on the size of the stack
 * @param a The first stack
 * @param b The second stack
 */
void	sort(t_stack *a, t_stack *b);
/** 
 * Sorts the stack using the bucket sort algorithm
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 */
void	bucket_sort(t_stack *a, t_stack *b, bool print);

/**
 * Sorts the stack using the selection sort algorithm
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 */
void	selection_sort(t_stack *a, t_stack *b, bool print);

/**
 * Sorts the stack using the counting sort algorithm
 * @param stack The stack to sort
 * @returns A pointer to the sorted array
 */
int		*counting_sort(t_stack *stack);

// * SWAP
/**
 * Swaps the first two elements of the stack
 * @param a The first stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		sa(t_stack *a, bool print);
/**
 * Swaps the first two elements of the stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		sb(t_stack *b, bool print);
/**
 * Swaps the first two elements of both stacks
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (2 if both stacks were swapped, 1 if only one stack was swapped, 0 otherwise)
 */
int		ss(t_stack *a, t_stack *b, bool print);

// * PUSH
/**
 * Pushes the top element of stack b to stack a
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed 
 * 1 if the operation was performed, 0 otherwise)
 */
int		pa(t_stack *a, t_stack *b, bool print);
/**
 * Pushes the top element of stack a to stack b
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		pb(t_stack *a, t_stack *b, bool print);
/**
 * Pushes the minimum element of stack a to stack b
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 */
void	push_min_to_b(t_stack *a, t_stack *b, bool print);
/**
 * Pushes all elements of stack b to stack a
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 */
void	push_all_to_a(t_stack *a, t_stack *b, bool print);

// * ROTATE
/**
 * Rotates stack a (the first element becomes the last one)
 * @param a The first stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise
 */
int		ra(t_stack *a, bool print);
/**
 * Rotates stack b (the first element becomes the last one)
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		rb(t_stack *b, bool print);
/**
 * Rotates both stacks a and b (the first element becomes the last one)
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed (2 if both stacks were rotated,
 * 1 if only one stack was rotated, 0 otherwise)
 */
int		rr(t_stack *a, t_stack *b, bool print);

/**
 * Calculates the cost of rotating a stack to bring an element to the top
 * @param pos The position of the element in the stack (0-based index)
 * @param size The size of the stack
 * @returns The cost of rotating the stack to bring the element to the top
 * (positive for clockwise rotations, negative for counter-clockwise rotations)
 */
int		rotation_cost(int pos, int size);

/**
 * Rotates stack a n times
 * @param a The first stack
 * @param cost The number of times to rotate
 * @param print Whether to print the operations performed
 */
void	rotate_a_n_times(t_stack *a, int cost, bool print);

/**
 * Rotates stack b n times
 * @param b The second stack
 * @param cost The number of times to rotate
 * @param print Whether to print the operations performed
 */
void	rotate_b_n_times(t_stack *b, int cost, bool print);

/**
 * Executes the rotations needed to move elements between stacks
 * @param a The first stack
 * @param b The second stack
 * @param cost_a Pointer to the cost of rotating stack a
 * @param cost_b Pointer to the cost of rotating stack b
 */
void	exec_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b);

/**
 * Brings the minimum element to the top of stack a
 * @param a The first stack
 * @param print Whether to print the operations performed
 */
void	bring_min_to_top(t_stack *a, bool print);

// * REVERSE ROTATE
/**
 * Reverses the order of elements in stack a
 * (the last element becomes the first one)
 * @param a The first stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		rra(t_stack *a, bool print);
/**
 * Reverses the order of elements in stack b
 * (the last element becomes the first one)
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed
 * (1 if the operation was performed, 0 otherwise)
 */
int		rrb(t_stack *b, bool print);
/**
 * Reverses the order of elements in both stacks a and b
 * (the last element becomes the first one)
 * @param a The first stack
 * @param b The second stack
 * @param print Whether to print the operations performed
 * @returns the number of operations performed (2 if both stacks were reversed,
 * 1 if only one stack was reversed, 0 otherwise)
 */
int		rrr(t_stack *a, t_stack *b, bool print);

// * UTILITY FUNCTIONS
/**
 * Returns the minimum value of the stack with its distance to both first
 * and last element of the stack
 * @param stack The stack to get the minimum value from
 * @returns A pointer to the minimum element of the stack with its distance
 * to both first and last element of the stack
 */
t_elem	*get_min_value(t_stack *stack);
/**
 * Sets the index of each element in the stack based on its value
 * (the smallest value gets index 0, the second smallest gets index 1, and so on)
 * @param stack The stack to set the indexes for
 */
void	set_indexes(t_stack *stack);

/**
 * Finds the best move to transfer an element from stack b to stack a
 * @param a The first stack
 * @param b The second stack
 * @param cost_a Pointer to store the cost of rotating stack a
 * @param cost_b Pointer to store the cost of rotating stack b
 */
void	get_best_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b);

/**
 * Checks if a character is a sign (+ or -)
 * @param c The character to check
 * @returns true if the character is a sign, false otherwise
 */
static inline bool	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

/**
 * Checks if a character is a valid digit (0-9)
 * @param c The character to check
 * @returns true if the character is a valid digit, false otherwise
 */
static inline bool	is_valid_char(char c)
{
	return (ft_isdigit(c) || ft_is_sign(c));
}

/**
 * Checks if a string represents a valid integer
 * @param s The string to check
 * @returns true if the string represents a valid integer, false otherwise
 */
static inline bool	ft_is_integer(const char *s)
{
	long	n;

	if (!s || !*s)
		return (false);
	n = ft_atol(s);
	return (n >= INT_MIN && n <= INT_MAX);
}

#endif