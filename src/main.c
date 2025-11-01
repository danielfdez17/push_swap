

#include "../inc/headers/push_swap.h"

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
 // ! 100% = 500 en menos de 5500 movimientos

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1 || (ac == 2 && !av[1][0]))
// 		return (1);
// 	if (ac == 2)
// 		av = ft_split(av[1], ' ');
// 	init_stack_a(&a, av + 1);
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, 0);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	return (0);
// }

// static int	ft_is_valid(char c)
// {
// 	return (ft_isalpha(0) || c == '-' || c == ' ');
// }
 
// static int	ft_validate_input(char *input)
// {
// 	while (input && *input)
// 	{
// 		if (!ft_is_valid(*input))
// 			return (0);
// 		++input;
// 	}
// 	return (1);
// }

// int main(int ac, char **av)
// {
// 	(void)av;
// 	int i = 1;
// 	t_stack *a = NULL;
// 	t_stack *a_copy = NULL;
// 	t_stack *b = NULL;
// 	t_stack *elem = NULL;
// 	while (i < ac)
// 	{
// 		elem = list_new(atoi(av[i]));
// 		push_back(&a, elem);		
// 		// elem = list_new(atoi(av[i]));
// 		// push_back(&a_copy, elem);
// 		++i;
// 	}
// 	a_copy = copy_list(a);
// 	// print_list(a, A);
// 	// print_list(a_copy, A);
// 	// print_list(b, B);
// 	selection_sort(a, b);
// 	// ft_printf("selection_sort: %d\n", selection_sort(a, b));
// 	// print_list(a, A);
// 	// print_list(b, B);
// 	free_list(a);
// 	// ft_printf("-------------------\n");
// 	a = a_copy;
// 	// print_list(a, A);
// 	// print_list(b, B);
// 	// ft_printf("radix_sort: %d\n", radix_sort(&a, &b, ac - 1));
// 	// print_list(a, A);
// 	// print_list(b, B);
// 	free_list(a);
// 	// free_list(a_copy);
// 	free_list(b);
// 	// ft_printf("%lu %lu\n", sizeof('a'), sizeof(int));
// 	// t_stack *stack_a = NULL;
// 	// t_stack *stack_b = NULL;
// 	// push_back(&stack_a, 2);
// 	// push_back(&stack_a, 1);
// 	// push_back(&stack_a, 3);
// 	// push_back(&stack_a, 6);
// 	// push_back(&stack_a, 5);
// 	// push_back(&stack_a, 8);
// 	// ft_printf("\n---Init a and b\n");
// 	// print(stack_a, stack_b);
// 	// ft_printf("\n---Exec sa\n");
// 	// swap(stack_a);
// 	// print(stack_a, stack_b);
// 	// ft_printf("\n---Exec pb\n");
// 	// push(&stack_b, &stack_a);
// 	// print(stack_a, stack_b);
// 	// ft_printf("\n---Exec pb\n");
// 	// push(&stack_b, &stack_a);
// 	// print(stack_a, stack_b);
// 	// // ft_printf("---Exec pb\n");
// 	// // push(&stack_b, &stack_a);
// 	// // print(stack_a, stack_b);
// 	// free_list(stack_a);
// 	// free_list(stack_b);
// 	return (0);
// }