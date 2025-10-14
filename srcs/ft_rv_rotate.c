#include "push_swap.h"

void	ft_rv_rotate(t_pile **lst)
{
	t_pile	*temp;
	t_pile	*temp_fin;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	temp_fin = (*lst);
	while (temp_fin->next != NULL)
		temp_fin = temp_fin->next;
	while (temp)
	{
		if (temp->next == temp_fin)
		{
			temp->next = NULL;
			break;
		}
		temp = temp->next;
	}
	ft_lstadd_front(lst, temp_fin);
}

void	ft_rv_rotate_rrr(t_pile **lst_a, t_pile **lst_b)
{
	if ((!lst_a || !(*lst_a) || !(*lst_a)->next) && (!lst_b || !(*lst_b) || !(*lst_b)))
		return ;
	else if ((!(lst_a) || !(*lst_a) || !(*lst_a)->next) && (*lst_b))
		ft_rv_rotate(lst_b);
	else if ((*lst_a) && (!(lst_b) || !(*lst_b) || !(*lst_b)->next))
		ft_rv_rotate(lst_a);
	else
	{
		ft_rv_rotate(lst_a);
		ft_rv_rotate(lst_b);
	}
}