/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:31 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:43:59 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "stack.h"

# ifndef DEBUG_MODE
# define DEBUG_MODE false
# endif

# ifndef DEFAULT_CHUNK_SIZE
#  define DEFAULT_CHUNK_SIZE 40
# endif

// * ARGUMENTS PROCESSING
bool	process_arguments(int ac, char **av, t_stack *a);

// * ERROR HANDLING
bool	input_error(char *s);
bool	free_error(t_stack *stack);

// * SORTING ALGORITHMS
void	sort(t_stack *a, t_stack *b);
void	bucket_sort(t_stack *a, t_stack *b, bool print);
void	selection_sort(t_stack *a, t_stack *b, bool print);
void	radix_sort(t_stack *a, t_stack *b, bool print);
int		*counting_sort(t_stack *stack);

// * SWAP
int		sa(t_stack *a, bool print);
int		sb(t_stack *b, bool print);
int		ss(t_stack *a, t_stack *b, bool print);

// * PUSH
int		pa(t_stack *a, t_stack *b, bool print);
int		pb(t_stack *a, t_stack *b, bool print);
void	push_min_to_b(t_stack *a, t_stack *b, bool print);
void	push_all_to_a(t_stack *a, t_stack *b, bool print);

// * ROTATE
int		ra(t_stack *a, bool print);
int		rb(t_stack *b, bool print);
int		rr(t_stack *a, t_stack *b, bool print);

// * REVERSE ROTATE
int		rra(t_stack *a, bool print);
int		rrb(t_stack *b, bool print);
int		rrr(t_stack *a, t_stack *b, bool print);

// * UTILITY FUNCTIONS
t_elem	*get_min_value(t_stack *stack);
t_elem	*get_max_value(t_stack *stack);
void	set_indexes(t_stack *stack);

static inline bool	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

static inline bool	is_valid_char(char c)
{
	return (ft_isdigit(c) || ft_is_sign(c));
}

static inline bool	ft_is_integer(const char *s)
{
	long	n;

	if (!s || !*s)
		return (false);
	n = ft_atol(s);
	return (n >= INT_MIN && n <= INT_MAX);
}

#endif