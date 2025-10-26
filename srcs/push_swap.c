/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_pile	*stack_a;
	t_pile	*stack_b;
	t_pile	*list_new;
	t_pile	*copie_a;

	if (ac < 2)
		return (1);
	ps = malloc(sizeof(t_ps));
	ft_init(&stack_a, &stack_b, &list_new, &copie_a);
	if (!ps)
		return (1);
	ps->error = 0;
	ps->arg = 1;
	if (ac == 2)
		return (ft_ac_2(&stack_a, &list_new, &ps, av),
			ft_check_sorted_1234(&stack_a, &stack_b, &ps, ac),
			ft_index_radix(&stack_a, &stack_b, &copie_a),
			ft_lst_clear(&copie_a),
			ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
	while (ps->arg < ac)
		ft_ac_pl(&stack_a, &list_new, &ps, av);
	return (ft_check_sorted_1234(&stack_a, &stack_b, &ps, ac),
		ft_index_radix(&stack_a, &stack_b, &copie_a), ft_lst_clear(&copie_a),
		ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
}
