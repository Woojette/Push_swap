#include "push_swap.h"

void	ft_rotate(t_pile **lst)
{
	t_pile	*temp_lst;
	int		temp_content;

	if (!lst || !(*lst))
		return ;
	temp_lst = (*lst);
	temp_content = temp_lst->content;
	while (temp_lst->next)
		temp_lst = temp_lst->next;
	temp_lst->content = temp_content;
	(*lst) = (*lst)->next;
}
