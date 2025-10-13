#include "push_swap.h"

void	ft_swap(t_pile **lst)
{
	t_pile	*temp_1;
	t_pile	*temp_2;
	// t_pile	*temp_1;
	// t_pile	*temp_2;

	if (!(*lst))
		return ;
	temp_1 = (*lst);
	temp_2 = (*lst);
	temp_1 = temp_1->next;
	(*lst)->content = temp_1->content;
	(*lst) = (*lst)->next;
	(*lst)->content = temp_2->content;
	(*lst) = temp_2;
	// temp_1 = ft_lstnew(temp_lst->content);
	// if (!(temp_lst->next))
	// 	return ;
	// temp_2 = ft_lstnew(temp_lst->content);

	// if (!(temp_lst->next))
	// {
	// 	ft_lstadd_back(&temp_2, temp_1);
	// 	(*lst) = temp_2;
	// 	return ;
	// }
	// ft_lstadd_front(&temp_lst, temp_1->content);
	// ft_lstadd_front(&temp_lst, temp_2->content);
	// (*lst) = temp_lst;
}
