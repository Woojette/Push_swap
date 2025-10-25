/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_pile **lst)
{
	t_pile	*temp_lst;
	int		index;

	if (!lst || !(*lst))
		return ;
	temp_lst = (*lst);
	index = 0;
	while (temp_lst)
	{
		temp_lst->index = index;
		temp_lst = temp_lst->next;
		index++;
	}
}

void	ft_index_copie(t_pile **lst, t_pile **copie)
{
	t_pile	*temp_copie;
	t_pile	*temp_lst;

	if (!copie || !(*copie) || !lst || !(*lst))
		return ;
	temp_copie = (*copie);
	temp_lst = (*lst);
	while (temp_lst)
	{
		while (temp_copie)
		{
			if ((temp_lst->content) == (temp_copie->content))
			{
				temp_lst->index = temp_copie->index;
				break ;
			}
			temp_copie = temp_copie->next;
		}
		temp_copie = (*copie);
		temp_lst = temp_lst->next;
	}
}
