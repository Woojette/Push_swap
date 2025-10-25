/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compter_bits_max(t_pile *lst)
{
	int	max;
	int	temp_max;
	int	bits_max;

	if (!lst)
		return (0);
	max = ft_check_max_index(lst);
	temp_max = max;
	bits_max = 0;
	while (temp_max > 1)
	{
		temp_max = max >> bits_max;
		bits_max++;
	}
	return (bits_max);
}

void	ft_check_position_bits(t_pile **lst_a, t_pile **lst_b, int p_bits)
{
	if (!lst_a || !(*lst_a))
		return ;
	if ((((*lst_a)->index) >> p_bits) & 1)
		ft_rotate_a(&(*lst_a));
	else if (((((*lst_a)->index) >> p_bits) & 1) == 0)
		ft_push_pb(lst_a, lst_b);
}

void	ft_radix(t_pile **lst_a, t_pile **lst_b)
{
	int	position_bits;
	int	size;
	int	repeter;
	int	bits_max;

	if (!lst_a || !(*lst_a))
		return ;
	position_bits = 0;
	size = ft_compter_val((*lst_a));
	repeter = 0;
	bits_max = ft_compter_bits_max((*lst_a));
	while (bits_max > position_bits)
	{
		while (size > repeter)
		{
			if (!(*lst_a))
				break ;
			ft_check_position_bits(lst_a, lst_b, position_bits);
			repeter++;
		}
		while ((*lst_b))
			ft_push_pa(lst_a, lst_b);
		position_bits++;
		repeter = 0;
	}
}
