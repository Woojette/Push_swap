#include "push_swap.h"

void	ft_swap(t_pile **lst)
{
	t_pile	*temp_lst;
	int		temp_content_1;
	int		temp_content_2;

	if (!(*lst))
		return ;
	temp_lst = (*lst);
	temp_content_1 = temp_lst->content;
	if (temp_lst->next == NULL)
		return ;
	temp_lst = temp_lst->next;
	temp_content_2 = temp_lst->content;
	temp_lst->content = temp_content_1;
	(*lst)->content = temp_content_2;
}

void	ft_swap_a(t_pile **lst)
{
	ft_swap(lst);
	ft_printf("sa\n");
}

void	ft_swap_b(t_pile **lst)
{
	ft_swap(lst);
	ft_printf("sb\n");

}

void	ft_swap_ss(t_pile **lst_a, t_pile **lst_b)
{
	if ((!(lst_a) || !(*lst_a)) && (!(lst_b) || !(*lst_b)))
		return ;
	else if ((!(lst_a) || !(*lst_a)) && (*lst_b))
		ft_swap(lst_b);
	else if ((*lst_a) && (!(lst_b) || !(*lst_b)))
		ft_swap(lst_a);
	else
	{
		ft_swap(lst_a);
		ft_swap(lst_b);
	}
	ft_printf("ss\n");
}
