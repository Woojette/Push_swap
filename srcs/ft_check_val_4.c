/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_val_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_val_4_pb_0(t_pile *lst)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	if (!lst)
		return (0);
	n1 = lst->content;
	lst = lst->next;
	n2 = lst->content;
	lst = lst->next;
	n3 = lst->content;
	lst = lst->next;
	n4 = lst->content;
	if (n1 > n2  &&  n1 < n3  &&  n3 < n4)
		return (1);
	if (n1 < n2  &&  n2 < n3  &&  n1 > n4)
		return (1);
	if (n2 < n3  &&  n3 < n4  &&  n4 < n1)
		return (1);
	return (0);
}

void	ft_val_4_pb_0(t_pile **lst_a)
{
	t_pile	*temp_lst;
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	if (!lst_a || !(*lst_a))
		return ;
	temp_lst = (*lst_a);
	n1 = temp_lst->content;
	temp_lst = temp_lst->next;
	n2 = temp_lst->content;
	temp_lst = temp_lst->next;
	n3 = temp_lst->content;
	temp_lst = temp_lst->next;
	n4 = temp_lst->content;
	if (n1 > n2  &&  n1 < n3  &&  n1 < n4  &&  n3 < n4)
		ft_swap_a(lst_a);
	if (n1 < n2  &&  n2 < n3  &&  n1 > n4)
		ft_rv_rotate_a(lst_a);
	if (n2 < n3  &&  n3 < n4  &&  n4 < n1)
		ft_rotate_a(lst_a);
}

void	ft_min_push_4(t_pile **lst_a, t_pile **lst_b, int min)
{
	t_pile *temp_lst;
	int		ordre;

	if (!lst_a || !(*lst_a))
		return ;
	temp_lst = (*lst_a);
	ordre = 1;
	while (temp_lst)
	{
		if (temp_lst->content == min)
			break ;
		temp_lst = temp_lst->next;
		ordre++;
	}
	if (ordre == 2)
		ft_swap_a(lst_a);
	else if (ordre == 3)
	{
		ft_rotate_a(lst_a);
		ft_swap_a(lst_a);
	}
	else if (ordre == 4)
		ft_rv_rotate_a(lst_a);
	ft_push_pb(lst_a, lst_b);
}

void	ft_check_val_4(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_lst;
	int		min;

	if (!lst_a || !(*lst_a))
		return ;
	temp_lst = (*lst_a);
	if (ft_check_val_4_pb_0(temp_lst))
	{
		ft_val_4_pb_0(lst_a);
		return ;
	}
	min = ft_check_min(temp_lst);
	ft_min_push_4(lst_a, lst_b, min);
	if (ft_compter_val((*lst_a)) == 3)
		ft_check_val_a_123(lst_a);
	ft_push_pa(lst_a, lst_b);
}
