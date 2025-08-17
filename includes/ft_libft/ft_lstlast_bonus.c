/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:21:49 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/16 18:26:27 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
		
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*last;

	list = malloc(sizeof(t_list));
	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	last = malloc(sizeof(t_list));
	list->content = "premier";
	list->next = node1;
	node1->content = "deuxieme";
	node1->next = node2;
	node2->content = "troisieme";
	node2->next = last;
	last->content = "last";
	last->next = NULL;
	last = ft_lstlast(list);
	if (last)
		printf("last element content : %s\n", (char *)last->content);
	else
		printf("last vide\n");
	return (0);
}*/
