

#include "../inc/headers/push_swap.h"


void	swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	swap(t_list *list)
{
	printf("Swapping values\n");
	if (!list || !list->next)
		return (0);
	swap_values(&list->value, &list->next->value);
	return (1);
}

int	ss(t_list *a, t_list *b)
{
	return (swap(a) + swap(b));
}