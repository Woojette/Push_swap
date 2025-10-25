/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_lstnew(int content)
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

t_pile	*ft_lstmap(t_pile *lst, int (*f)(t_pile *lst), void (*del)(void *))
{
	t_pile	*lst_new;
	t_pile	*lst_ajoute;
	int		content_new;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		content_new = f(lst);
		lst_ajoute = ft_lstnew(content_new);
		if (!lst_ajoute)
			return (ft_lst_clear(&lst_new), NULL);
		ft_lstadd_back(&lst_new, lst_ajoute);
		lst = lst->next;
	}
	return (lst_new);
}
