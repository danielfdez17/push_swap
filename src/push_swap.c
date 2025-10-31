

#include "push_swap.h"

/** usefull gdb commands
 * break <line_number>
 * info break
 * delete <breakpoint_number>
 * lay next
 * shell clear
 * call <function>
 * print <var> // print <param>
 * gdb -tui to see the Text User Interface
 * list
 */

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int i = 1;
	t_list *a = NULL;
	t_list *b = NULL;
	t_list *elem = NULL;
	while (i < ac)
	{
		elem = list_new(atoi(av[i]));
		push_back(&a, elem);		
		++i;
	}
	print_list(a);
	selection_sort(a, b);
	free_list(a);
	// t_list *stack_a = NULL;
	// t_list *stack_b = NULL;
	// push_back(&stack_a, 2);
	// push_back(&stack_a, 1);
	// push_back(&stack_a, 3);
	// push_back(&stack_a, 6);
	// push_back(&stack_a, 5);
	// push_back(&stack_a, 8);
	// printf("\n---Init a and b\n");
	// print(stack_a, stack_b);
	// printf("\n---Exec sa\n");
	// swap(stack_a);
	// print(stack_a, stack_b);
	// printf("\n---Exec pb\n");
	// push(&stack_b, &stack_a);
	// print(stack_a, stack_b);
	// printf("\n---Exec pb\n");
	// push(&stack_b, &stack_a);
	// print(stack_a, stack_b);
	// // printf("---Exec pb\n");
	// // push(&stack_b, &stack_a);
	// // print(stack_a, stack_b);
	// free_list(stack_a);
	// free_list(stack_b);
	return (0);
}