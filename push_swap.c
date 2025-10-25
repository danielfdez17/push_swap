

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *list = list_new(5);
	push_back(list, 8);
	push_front(&list, 6);
	print_list(list);
	// t_list *front = pop_front(&list);
	// print_list(front);
	rotate(list);
	print_list(list);
	reverse_rotate(list);
	print_list(list);
	free_list(list);
	// free_list(front);
	return (0);
}