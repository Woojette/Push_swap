#include "push_swap.h"

t_pile	*ft_lstnew(int	content)
{
	t_pile	*lst;

	lst = malloc(sizeof(t_pile));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	// lst->valeur = 12;
	return (lst);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*temp;
	// temp = malloc(sizeof(t_list));
	// if (!temp)
	// 	return ;
	temp = *lst;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next != NULL)
	{

		(*lst) = (*lst)->next;
		// if (((*lst)->next) == NULL)
		// {
		// 	(*lst)->next = new;
		// 	break;
		// }
	}
	(*lst)->next = new;
	*lst = temp;
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