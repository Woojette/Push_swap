#include "push_swap.h"

void	ft_check_val_a_2(t_pile **lst)
{
	t_pile	*temp_fin;
	int		premier;
	int		seconde;

	temp_fin = (*lst)->next;
	premier = (*lst)->content;
	seconde = temp_fin->content;
	if (!lst || (temp_fin->next != NULL) || (premier < seconde))
		return ;
	ft_swap_a(lst);
}

void	ft_tri_a_3(int n1, int n2, int n3, t_pile **lst)
{
	if (!lst || !(*lst))
		return ;
	if (n1 < n2 && n1 < n3 && n2 < n3)
		return ;
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		ft_rv_rotate_a(lst);
		ft_swap_a(lst);
	}
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		ft_rv_rotate_a(lst);
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		ft_swap_a(lst);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		ft_swap_a(lst);
		ft_rv_rotate_a(lst);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ft_rotate_a(lst);
}

void	ft_check_val_a_3(t_pile **lst)
{
	t_pile	*temp_content;
	int		n1;
	int		n2;
	int		n3;

	temp_content = (*lst);
	n1 = temp_content->content;
	temp_content = temp_content->next;
	n2 = temp_content->content;
	temp_content = temp_content->next;
	n3 = temp_content->content;
	ft_tri_a_3(n1, n2, n3, lst);
}

void	ft_check_val_a_123(t_pile **lst)
{
	t_pile	*temp_lst;

	if (!lst || !(*lst))
		return ;
	temp_lst = (*lst);
	if (temp_lst->next == NULL)
		return ;
	temp_lst = temp_lst->next;
	if (temp_lst->next == NULL)
		ft_check_val_a_2(lst);
	temp_lst = temp_lst->next;
	if (temp_lst->next == NULL && temp_lst)
		ft_check_val_a_3(lst);
}
