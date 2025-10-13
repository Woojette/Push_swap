#include "push_swap.h"

void	ft_print_list(t_pile *list)
{
	while (list)
	{
		ft_printf("%d | ", list->content);
		list = list->next;
	}
}

void	ft_print_deux(t_pile *list_a, t_pile *list_b)
{
	ft_printf("A : ");
	if (!list_a)
		printf("vide");
	while (list_a)
	{
		ft_printf("%d | ", list_a->content);
		list_a = list_a->next;
	}
	ft_printf("\nB : ");
	if (!list_b)
		printf("vide");
	while (list_b)
	{
		ft_printf("%d | ", list_b->content);
		list_b = list_b->next;
	}
	ft_printf("\n");
}