#include "push_swap.h"

t_pile	*ft_lstnew(int	content)
{
	t_pile	*lst;

	lst = malloc(sizeof(t_pile));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	ft_lst_clear(t_pile **lst)
{
	t_pile	*temp;

	if (!(*lst))
		return ;
	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}