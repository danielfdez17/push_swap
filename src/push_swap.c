

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

 // ! 80% = 100 en menos de 700 movimientos
 // ! 80% = 500 en menos de 5500 movimientos

int main(int ac, char **av)
{
	(void)av;
	int i = 1;
	t_list *a = NULL;
	t_list *a_copy = NULL;
	t_list *b = NULL;
	t_list *elem = NULL;
	while (i < ac)
	{
		elem = list_new(atoi(av[i]));
		push_back(&a, elem);		
		// elem = list_new(atoi(av[i]));
		// push_back(&a_copy, elem);
		++i;
	}
	// * a_copy = copy_list(a);
	print_list(a, A);
	// print_list(a_copy, A);
	// print_list(b, B);
	printf("selection_sort: %d\n", selection_sort(a, b));
	print_list(a, A);
	// print_list(a_copy, A);
	print_list(b, B);
	free_list(a);
	free_list(a_copy);
	free_list(b);
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