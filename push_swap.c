

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	push_back(&stack_a, 2);
	// push_back(&stack_a, 1);
	// push_back(&stack_a, 3);
	// push_back(&stack_a, 3);
	// push_back(&stack_a, 3);
	// push_back(&stack_a, 8);
	a(stack_a);
	// b(stack_b);
	free_list(stack_a);
	return (0);
}