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
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef MAX_SELECTION_NUMBER
#  define MAX_SELECTION_NUMBER 50
# endif

typedef int	t_bool;

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
t_bool	syntax_error(char *s);
t_bool	duplicate_error(t_stack *stack, int n);
t_bool	free_error(t_stack **stack);

// * SORTING ALGORITHMS
void	sort_three(t_stack **stack, t_bool print);
void	selection_sort(t_stack **a, t_stack **b, t_bool print);
void	radix_sort(t_stack **a, t_stack **b, int size, t_bool print);
int		*counting_sort(t_stack *stack);

// * STACKS
t_bool	init_stack(t_stack **a, char **av);
int		get_size(t_stack *stack);
t_bool	is_stack_sorted(t_stack *stack);
t_stack	*get_max(t_stack *stack);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack *stack);
void	push_back(t_stack **stack, t_stack *elem);
void	push_front(t_stack **stack, t_stack *elem);
t_stack	*pop_front(t_stack **stack);
t_stack	*pop_back(t_stack **stack);

// * SWAP
int		sa(t_stack **a, t_bool print);
// int		sb(t_stack **b, t_bool print);
// int		ss(t_stack **a, t_stack **b, t_bool print);

// * PUSH
int		pa(t_stack **a, t_stack **b, t_bool print);
int		pb(t_stack **a, t_stack **b, t_bool print);

// * ROTATE
int		ra(t_stack **a, t_bool print);
// int		rb(t_stack **b, t_bool print);
// int		rr(t_stack **a, t_stack **b, t_bool print);

// * REVERSE ROTATE
int		rra(t_stack **a, t_bool print);
// int		rrb(t_stack **b, t_bool print);
// int		rrr(t_stack **a, t_stack **b, t_bool print);

#endif