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

void	ft_lstadd_front(t_pile **list, t_pile *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
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

