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

	if (ac < 2 || !av[0] || !av[1] || av[1][0] == '\0')
		return (1);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (1);
	ft_init(&stack_a, &stack_b, &list_new, &copie_a);
	ft_init_ps(&ps);
	if (ac == 2)
		ft_ac_2(&stack_a, &list_new, &ps, av);
	else
	{
		while (ps->arg < ac)
			ft_ac_pl(&stack_a, &list_new, &ps, av);
	}
	return (ft_check_sorted_1234(&stack_a, &stack_b, &ps, ac),
		ft_index_radix(&stack_a, &stack_b, &copie_a),
		ft_lst_clear(&copie_a),
		ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
}
