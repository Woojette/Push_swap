#include "push_swap.h"

void	ft_print_list(t_pile *lst)
{
	while (lst)
	{
		ft_printf("[%d] %d | ", lst->index, lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ft_print_deux_content(t_pile *list_a, t_pile *list_b)
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

void	ft_print_deux_tout(t_pile *list_a, t_pile *list_b)
{
	ft_printf("A : ");
	if (!list_a)
		printf("vide");
	while (list_a)
	{
		ft_printf("[%d] %d | ", list_a->index, list_a->content);
		list_a = list_a->next;
	}
	ft_printf("\nB : ");
	if (!list_b)
		printf("vide");
	while (list_b)
	{
		ft_printf("[%d] %d | ", list_b->index, list_b->content);
		list_b = list_b->next;
	}
	ft_printf("\n");
}