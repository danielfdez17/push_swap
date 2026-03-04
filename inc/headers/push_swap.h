/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:49:22 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# ifndef MAX_SELECTION_NUMBER
#  define MAX_SELECTION_NUMBER 50
# endif

typedef struct s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	int				value;
	int				index;
}	t_stack;

typedef struct s_value
{
	int	front;
	int	value;
	int	back;
}	t_value;

typedef struct s_limits
{
	long	min;
	long	max;
}	t_limits;

// * ERROR HANDLING
bool	input_error(char *s);
bool	duplicate_error(t_stack *stack, int n);
bool	free_error(t_stack **stack);

// * SORTING ALGORITHMS
void	sort_three(t_stack **stack, bool print);
void	selection_sort(t_stack **a, t_stack **b, bool print);
void	radix_sort(t_stack **a, t_stack **b, int size, bool print);
int		*counting_sort(t_stack *stack);

// * STACKS
bool	init_stack(t_stack **a, char **av);
int		get_size(t_stack *stack);
bool	is_stack_sorted(t_stack *stack);
t_stack	*get_max(t_stack *stack);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack **stack);
void	push_back(t_stack **stack, t_stack *elem);
void	push_front(t_stack **stack, t_stack *elem);
t_stack	*pop_front(t_stack **stack);
t_stack	*pop_back(t_stack **stack);

// * SWAP
int		sa(t_stack **a, bool print);
// int		sb(t_stack **b, bool print);
// int		ss(t_stack **a, t_stack **b, bool print);

// * PUSH
int		pa(t_stack **a, t_stack **b, bool print);
int		pb(t_stack **a, t_stack **b, bool print);

// * ROTATE
int		ra(t_stack **a, bool print);
// int		rb(t_stack **b, bool print);
// int		rr(t_stack **a, t_stack **b, bool print);

// * REVERSE ROTATE
int		rra(t_stack **a, bool print);
// int		rrb(t_stack **b, bool print);
// int		rrr(t_stack **a, t_stack **b, bool print);

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