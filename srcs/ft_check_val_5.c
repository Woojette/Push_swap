#include "push_swap.h"

int	ft_check_pb_0(t_pile *lst)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		n5;

	if (!lst)
		return (0);
	n1 = lst->content;
	lst = lst->next;
	n2 = lst->content;
	lst = lst->next;
	n3 = lst->content;
	lst = lst->next;
	n4 = lst->content;
	lst = lst->next;
	n5 = lst->content;
	if (n1 > n2  &&  n1 < n3  &&  n3 < n4  &&  n4 < n5)
		return (1);
	if (n1 < n2  &&  n2 < n3  &&  n3 < n4  &&  n5 < n1)
		return (1);
	if (n2 < n3  &&  n3 < n4  &&  n4 < n5  &&  n5 < n1)
		return (1);
	return (0);
}

void	ft_val_5_pb_0(t_pile **lst_a)
{
	t_pile	*temp_lst;
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		n5;

	if (!lst_a || !(*lst_a))
		return ;
	temp_lst = (*lst_a);
	n1 = temp_lst->content;
	temp_lst = temp_lst->next;
	n2 = temp_lst->content;
	temp_lst = temp_lst->next;
	n3 = temp_lst->content;
	temp_lst = temp_lst->next;
	n4 = temp_lst->content;
	temp_lst = temp_lst->next;
	n5 = temp_lst->content;
	if (n1 > n2  &&  n1 < n3  &&  n3 < n4  &&  n4 < n5)
		ft_swap_a(lst_a);
	if (n1 < n2  &&  n2 < n3  &&  n3 < n4  &&  n5 < n1)
		ft_rv_rotate_a(lst_a);
	if (n2 < n3  &&  n3 < n4  &&  n4 < n5  &&  n5 < n1)
		ft_rotate_a(lst_a);
}

void	ft_min_push_5(t_pile **lst_a, t_pile **lst_b, int min)
{
	t_pile *temp_lst;
	int		ordre;

	if (!lst_a || !(*lst_a))
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
	{
		ft_rv_rotate_a(lst_a);
		ft_rv_rotate_a(lst_a);
	}
	else if (ordre == 5)
		ft_rv_rotate_a(lst_a);
	ft_push_pb(lst_a, lst_b);
}

void	ft_check_val_5(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_lst;
	int		min1;
	int		min2;

	if (!lst_a || !(*lst_a) || (*lst_b))
		return ;
	temp_lst = (*lst_a);
	if (ft_check_pb_0(temp_lst))
	{
		ft_val_5_pb_0(lst_a);
		return ;
	}
	min1 = ft_check_min(temp_lst);

	ft_printf("min1 1 : %d\n", min1);
	ft_print_deux((*lst_a), (*lst_b));

	ft_min_push_5(lst_a, lst_b, min1);
	ft_print_deux((*lst_a), (*lst_b));
	ft_printf("min1 : %d\n", min1);
	// ft_printf("fonction %d\n", ft_check_val_4_pb_0((*lst_a)));
	if (ft_check_val_4_pb_0((*lst_a)))
	{
		ft_check_val_4(lst_a, lst_b);
		ft_push_pa(lst_a, lst_b);
		return ;
	}

	// ft_printf("\n%d\n", min1);
	min2 = ft_check_min((*lst_a));
	// ft_printf("\n1 : %d\n", min2);
	ft_min_push_4(lst_a, lst_b, min2);
	// ft_printf("\n2 : %d\n", min2);
	if (ft_compter_val((*lst_a)) == 3)
		ft_check_val_a_123(lst_a);
	ft_push_pa(lst_a, lst_b);
	ft_push_pa(lst_a, lst_b);
}
