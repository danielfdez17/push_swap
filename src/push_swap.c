

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1);
	size = get_size(a);
	if (!is_stack_sorted(a))
	{
		if (size == 2)
			sa(&a, 1);
		else if (size == 3)
			sort_three(&a, 1);
		// else if (size < 200)
		// 	turk_sort(&a, &b, 1);
		else
			// turk_sort(&a, &b, 1);
			size = radix_sort(&a, &b, size, 1);
	}
	// ft_printf("movs number: %d\n", size);
	free_stack(a);
	free_stack(b);
}
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	t_stack *a = NULL;
// 	t_stack *b = NULL;
// 	t_stack *elem = NULL;
// 	while (i < ac)
// 	{
// 		elem = list_new(ft_atoi(av[i]));
// 		if (!elem)
// 		{
// 			free_stack(a);
// 			ft_printf("Error in malloc\n");
// 			return (0);
// 		}
// 		push_back(&a, elem);		
// 		++i;
// 	}
// 	// ft_printf("selection_sort: %d\n", selection_sort(a, b));
// 	// ft_printf("radix_sort: %d\n", radix_sort(&a, &b, ac - 1));
// 	// radix_sort(&a, &b, ac - 1);
// 	turk_sort(&a, &b);
// 	free_stack(a);
// 	free_stack(b);
// 	return (0);
// }