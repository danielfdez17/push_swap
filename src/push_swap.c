

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

int main(int ac, char **av)
{
	int i = 1;
	t_stack *a = NULL;
	t_stack *b = NULL;
	t_stack *elem = NULL;
	while (i < ac)
	{
		elem = list_new(ft_atoi(av[i]));
		if (!elem)
		{
			free_list(a);
			ft_printf("Error in malloc\n");
			return (0);
		}
		push_back(&a, elem);		
		++i;
	}
	ft_printf("selection_sort: %d\n", selection_sort(a, b));
	// ft_printf("radix_sort: %d\n", radix_sort(&a, &b, ac - 1));
	free_list(a);
	free_list(b);
	return (0);
}