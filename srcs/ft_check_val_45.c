#include "push_swap.h"

int	ft_check_min(t_pile *lst)
{
	int	min;
	int	cmp;

	if (!lst)
		return (0);
	min = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		cmp = lst->content;
		if (min > cmp)
			min = cmp;
	}
	return (min);
}

void	ft_min_push(t_pile **lst_a, t_pile **lst_b, int min)
{
	t_pile *temp_lst;
	int		ordre;

	if (!lst_a || !(*lst_a) || (*lst_b))
		return ;
	temp_lst = (*lst_a);
	ordre = 1;
	while (temp_lst)
	{
		if (temp_lst->content == min)
			break ;
		temp_lst = temp_lst->next;
		ordre++;
	}
	if (ordre == 2)
		ft_swap_a(lst_a);
	else if (ordre == 3)
	{
		ft_rotate_a(lst_a);
		ft_swap_a(lst_a);
	}
	else if (ordre == 4)
		ft_rv_rotate_a(lst_a);
	ft_push_pb(lst_a, lst_b);
}

void	ft_check_val_4(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_lst;
	int		min;

	if (!lst_a || !(*lst_a) || (*lst_b))
		return ;
	temp_lst = (*lst_a);
	min = ft_check_min(temp_lst);
	ft_min_push(lst_a, lst_b, min);
	if (ft_compter_val((*lst_a)) == 3)
		ft_check_val_a_123(lst_a);
	ft_push_pa(lst_a, lst_b);
}
