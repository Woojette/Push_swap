#include "push_swap.h"

int main(int ac, char **av)
{
	t_ps	*ps;
	t_pile	*stack_a;
	t_pile	*stack_b;
	t_pile	*list_new;

	ps = malloc(sizeof(t_ps));
	stack_a = NULL;
	stack_b = NULL;
	list_new = NULL;
	
	if (!ps)
		return (1);
	ps->error = 0;
	if (ac < 2)
		return (ft_printf("\n"), 1);
	ps->arg = 1;

	if (ac == 2)
	{
		ps->arg = 0;
		ps->av_splite = ft_split(av[1], ' ');

		while (ps->av_splite[ps->arg])
		{
			if (ft_check_av(ps->av_splite[ps->arg], stack_a) == 1)
				return (ft_lst_clear(&stack_a), free(ps), 1);
			list_new = ft_lstnew(ft_atoi(ps->av_splite[ps->arg], &ps->error));
			ft_lstadd_back(&stack_a, list_new);
			ps->arg++;
		}
		if (ft_if_sorted(stack_a, stack_b))
			return (ft_printf("\n"), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
		if (ft_compter_val_a(stack_a, stack_b) <= 3)
			return (ft_check_val_a_123(&stack_a), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
		if (ft_compter_val_a(stack_a, stack_b) == 4)
			return (ft_check_val_4(&stack_a, &stack_b), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);

			// ft_printf("    ");
		// ft_print_list(stack_a);
	
		// I. parsing
		// 1) test_swap
		// ft_printf("ss\n");
		// ft_swap_ss(&stack_a, &stack_b);
		// ft_print_list(stack_a);
		// printf("\n");
		// ft_print_list(stack_b);

		// 2) test_rotate
		// ft_printf("\nrr\n");
		// ft_rotate_rr(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);

		// 3) test_rv_rotate
		// ft_printf("\nrv rotate\n");
		// ft_rv_rotate_rrr(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);

		// 4_1) test_push_pb
		// ft_print_deux(stack_a, stack_b);
		// ft_printf("\npush pb\n");
		// ft_push_pb(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);
		// ft_printf("\npush pb\n");
		// ft_push_pb(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);

		// 4_2) test_push_pa
		// ft_printf("\n\n");
		// ft_printf("\npush pa\n");
		// ft_push_pa(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);
		// ft_printf("\npush pa\n");
		// ft_push_pa(&stack_a, &stack_b);
		// ft_print_deux(stack_a, stack_b);

		// II. Algorithme
		// int	i;

		// i = ft_if_sorted(stack_a, stack_b);
		// ft_printf("%d\n", i);



		ft_free_list(&stack_a, &stack_b, &ps, ac);
		return (0);
	}

	// Gerer le cas argc > 2
	while (ps->arg < ac)
	{
		if (ft_check_av(av[ps->arg], stack_a) == 1)
			return (ft_lst_clear(&stack_a), free(ps), 1);
		list_new = ft_lstnew(ft_atoi(av[ps->arg], &ps->error));
		ft_lstadd_back(&stack_a, list_new);
		ps->arg++;
	}

	// int	n;

	// n = ft_compter_val_a(stack_a, stack_b);
	// printf("nombre de liste : %d\n", n);

	if (ft_if_sorted(stack_a, stack_b))
		return (ft_printf("\n"), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
	if (ft_compter_val_a(stack_a, stack_b) <= 3)
		return (ft_check_val_a_123(&stack_a), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
	if (ft_compter_val_a(stack_a, stack_b) == 4)
		return (ft_check_val_4(&stack_a, &stack_b), ft_free_list(&stack_a, &stack_b, &ps, ac), 0);
	// ft_printf("    ");
	// ft_print_list(stack_a);

	// I. Parsing
	// 1) test_swap
	// ft_printf("ss\n");
	// ft_swap_ss(&stack_a, &stack_b);
	// ft_print_list(stack_a);
	// printf("\n");
	// ft_print_list(stack_b);

	// 2) test_rotate
	// ft_printf("\nrr\n");
	// ft_rotate_rr(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);

	// 3) test_rv_rotate
	// ft_printf("\nrv rotate\n");
	// ft_rv_rotate_rrr(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);

	// 4_1) test_push_pb
	// ft_print_deux(stack_a, stack_b);
	// ft_printf("\npush pb\n");
	// ft_push_pb(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);
	// ft_printf("\npush pb\n");
	// ft_push_pb(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);

	// 4_2) test_push_pa
	// ft_printf("\n\n");
	// ft_printf("\npush pa\n");
	// ft_push_pa(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);
	// ft_printf("\npush pa\n");
	// ft_push_pa(&stack_a, &stack_b);
	// ft_print_deux(stack_a, stack_b);

	// II. Algorithme
	// int	i;

	// i = ft_if_sorted(stack_a, stack_b);
	// ft_printf("%d\n", i);



	// if (ac == 2)
	// {
	// 	ps->arg = 0;
	// 	av = ft_split(av[1], ' '); //******* */ 
	// 	if (!av[2])
	// 	{
	// 		ft_atoi(av[0], &ps->error);
	// 		if (ps->error)
	// 			return (ft_printf("Error\nInt max/min\n"), 1);
	// 		return (ft_printf("\n"));
	// 	}
	// }

	// chiffre
	// while (ps->arg < ac)
	// {
	// 	i = 0;
	// 	while (av[ps->arg][i] != '\0')
	// 	{
	// 		if (av[ps->arg][i] == '+' || av[ps->arg][i] == '-')
	// 			i++;
	// 		if (ft_isdigit(av[ps->arg][i]) == 1)
	// 			return (ft_printf("Error\n"), 1);
	// 		i++;
	// 	}
	// 	ps->arg++;
	// }
	// ps->arg = 1;
	// while (av[ps->arg])
	// {
	// 	ps->arg2 = ps->arg + 1;
	// 	while (av[ps->arg2])
	// 	{
	// 		if (ft_atoi(av[ps->arg], &ps->error) == ft_atoi(av[ps->arg2], &ps->error))
	// 			return (ft_printf("Error\ndoublon\n"), 1);
	// 		if (ps->error)
	// 			return (ft_printf("Error\nInt max/min\n"), 1);
	// 		ps->arg2++;
	// 	}
	// 	ps->arg++;
	// }

	// int	repete;

	// repete = 0;
	// while (repete < ac -1)
	// {
	// 	ps->atoi_av1 = ft_atoi(av[repete +1], &ps->error);
	// 	// printf("%d\n", ps->atoi_av1);
	// 	list_new = ft_lstnew(ps->atoi_av1);
	// 	// printf("%d\n", list_new->content);
	// 	ft_lstadd_back(&stack_a, list_new);
	// 	repete++;
	// }
	// ft_print_list(stack_a);
	ft_free_list(&stack_a, &stack_b, &ps, ac);
	// ft_print_list(stack_a);
	return (0);
}