

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *list = list_new(1);
	push_back(list, 42);
	push_front(&list, -42);
	print_list(list);
	t_list *front = pop_front(&list);
	print_list(front);
	print_list(list);
	free_list(list);
	free_list(front);
	return (0);
}