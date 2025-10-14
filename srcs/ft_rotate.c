#include "push_swap.h"

void	ft_rotate(t_pile **lst)
{
	t_pile	*temp;
	t_pile	*temp_fin;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	temp_fin = (*lst);
	(*lst) = (*lst)->next;
	while (temp_fin->next != NULL)
		temp_fin = temp_fin->next;
	(*temp).next = NULL;
	temp_fin->next = temp;
}

void	ft_rotate_a(t_pile **lst)
{
	ft_rotate(lst);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_pile **lst)
{
	ft_rotate(lst);
	ft_printf("rb\n");
}

void	ft_rotate_rr(t_pile **lst_a, t_pile **lst_b)
{
	if ((!lst_a || !(*lst_a) || !(*lst_a)->next) && (!lst_b || !(*lst_b) || !(*lst_b)))
		return ;
	else if ((!(lst_a) || !(*lst_a) || !(*lst_a)->next) && (*lst_b))
		ft_rotate(lst_b);
	else if ((*lst_a) && (!(lst_b) || !(*lst_b) || !(*lst_b)->next))
		ft_rotate(lst_a);
	else
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
	}
	ft_printf("rr\n");
}
