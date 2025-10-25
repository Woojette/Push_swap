/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_min(t_pile *lst)
{
	int	min;
	int	cmp;

	if (!lst)
		return (0);
	min = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		cmp = lst->content;
		if (min > cmp)
			min = cmp;
	}
	return (min);
}

int	ft_check_max_index(t_pile *lst)
{
	int		n1;
	int		max;

	if (!lst)
		return (0);
	max = lst->next->index;
	while (lst)
	{
		n1 = lst->index;
		if (n1 > max)
			max = n1;
		lst = lst->next;
	}
	return (max);
}
