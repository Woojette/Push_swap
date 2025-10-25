/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_pb(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_b;

	if ((!(lst_a) || !(*lst_a)) && (!(lst_b) || !(*lst_b)))
		return ;
	if (!(lst_a) || !(*lst_a))
		return ;
	temp_b = (*lst_a);
	(*lst_a) = (*lst_a)->next;
	temp_b->next = NULL;
	if ((!(lst_b) || !(*lst_b)))
	{
		(*lst_b) = temp_b;
		ft_printf("pb\n");
		return ;
	}
	ft_lstadd_front(lst_b, temp_b);
	ft_printf("pb\n");
}

void	ft_push_pa(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_a;

	if ((!(lst_a) || !(*lst_a)) && (!(lst_b) || !(*lst_b)))
		return ;
	if (!(lst_b) || !(*lst_b))
		return ;
	temp_a = (*lst_b);
	(*lst_b) = (*lst_b)->next;
	temp_a->next = NULL;
	if ((!(lst_a) || !(*lst_a)))
	{
		(*lst_a) = temp_a;
		ft_printf("pa\n");
		return ;
	}
	ft_lstadd_front(lst_a, temp_a);
	ft_printf("pa\n");
}
