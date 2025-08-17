#include "push_swap.h"

void	ft_print_list(t_pile *list)
{
	while (list)
	{
		ft_printf("%d | ", list->content);
		list = list->next;
	}
}

int main(int ac, char **av)
{
	t_ps	*ps;
	t_pile	*list_a;
	t_pile	*list_b;
	t_pile	*list_new;
	int 	i;

	ps = malloc(sizeof(t_ps));
	list_a = NULL;
	list_b = NULL;
	list_new = NULL;
	
	if (!ps)
		return (1);
	list_a = NULL;
	ps->error = 0;
	if (ac < 2)
		return (ft_printf("\n"), 1);
	ps->arg = 1;
	if (ac == 2)
	{ 
		printf("test\n");
		ps->arg = 0;
		av = ft_split(av[1], ' '); //******* */ 
		if (!av[2])
		{
			ft_atoi(av[0], &ps->error);
			if (ps->error)
				return (ft_printf("Error\nInt max/min\n"), 1);
			return (ft_printf("\n"));
		}
	}
	// chiffre
	while (ps->arg < ac)
	{
		i = 0;
		while (av[ps->arg][i] != '\0')
		{
			if (av[ps->arg][i] == '+' || av[ps->arg][i] == '-')
				i++;
			if (ft_isdigit(av[ps->arg][i]) == 1)
				return (ft_printf("Error\n"), 1);
			i++;
		}
		ps->arg++;
	}
	ps->arg = 1;
	while (av[ps->arg])
	{
		ps->arg2 = ps->arg + 1;
		while (av[ps->arg2])
		{
			if (ft_atoi(av[ps->arg], &ps->error) == ft_atoi(av[ps->arg2], &ps->error))
				return (ft_printf("Error\ndoublon\n"), 1);
			if (ps->error)
				return (ft_printf("Error\nInt max/min\n"), 1);
			ps->arg2++;
		}
		ps->arg++;
	}

	int	repete;

	repete = 0;
	while (repete < ac -1)
	{
		ps->atoi_av1 = ft_atoi(av[repete +1], &ps->error);
		// printf("%d\n", ps->atoi_av1);
		list_new = ft_lstnew(ps->atoi_av1);
		// printf("%d\n", list_new->content);
		ft_lstadd_back(&list_a, list_new);
		repete++;
	}
	ft_print_list(list_a);
	ft_lst_clear(&list_a);
	free(ps);
	ft_print_list(list_a);
	return (0);
}