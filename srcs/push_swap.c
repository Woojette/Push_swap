#include "push_swap.h"

int main(int ac, char **av)
{
	t_ps	*ps;
	t_pile	*stack_a;
	t_pile	*stack_b;
	t_pile	*list_new;
	t_pile	*copie_a;

	if (ac < 2)
		return (1);
	ps = malloc(sizeof(t_ps));
	stack_a = NULL;
	stack_b = NULL;
	list_new = NULL;
	copie_a = NULL;
	if (!ps)
		return (1);
	ps->error = 0;
	ps->arg = 1;
	if (ac == 2)
	{
		ps->arg = 0;
		ps->av_splite = ft_split(av[1], ' ');
		while (ps->av_splite[ps->arg])
		{
			if (ft_check_av(ps->av_splite[ps->arg], stack_a) == 1)
				return (ft_lst_clear(&stack_a),ft_free_pl(ps->av_splite), free(ps), 1);
			list_new = ft_lstnew(ft_atoi(ps->av_splite[ps->arg], &ps->error));
			ft_lstadd_back(&stack_a, list_new);
			ps->arg++;
		}
		ft_check_sorted_1234(&stack_a, &stack_b, &ps, ac);
		ft_index_radix(&stack_a, &stack_b, &copie_a);
		return (ft_lst_clear(&copie_a), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
	}
	while (ps->arg < ac)
	{
		if (ft_check_av(av[ps->arg], stack_a) == 1)
			return (ft_lst_clear(&stack_a), free(ps), 1);
		list_new = ft_lstnew(ft_atoi(av[ps->arg], &ps->error));
		ft_lstadd_back(&stack_a, list_new);
		ps->arg++;
	}
	ft_check_sorted_1234(&stack_a, &stack_b, &ps, ac);
	ft_index_radix(&stack_a, &stack_b, &copie_a);
	return (ft_lst_clear(&copie_a), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
}
