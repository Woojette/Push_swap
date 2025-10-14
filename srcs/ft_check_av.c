#include "push_swap.h"

int	ft_int_check(char *av)
{
	int	i;

	i = 0;
	if (!av || av[0] == '\0')
		return (1);
	if (av[0] == '+' || av[0] == '-')
	{
		if (av[1] == '\0')
			return (1);
		i++;
	}
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_limit_check(char *av)
{
	int	error;

	error = 0;
	ft_atoi(av, &error);
	if (error == 1)
		return (1);
	return (0);
}

int	ft_dup_check(char *av, t_pile *lst)
{
	int		error;
	int		valeur;

	error = 0;
	valeur = ft_atoi(av, &error);
	if (error == 1)
		return (1);
	while (lst)
	{
		if (lst->content == valeur)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_check_av(char *av, t_pile *lst)
{
	if (ft_int_check(av) == 1)
		return (ft_printf("Error\nInt\n"), 1);
	if (ft_limit_check(av) == 1)
		return (ft_printf("Error\nInt max/min\n"), 1);
	if (ft_dup_check(av, lst) == 1)
		return (ft_printf("Error\nDoublons\n"), 1);
	return (0);
}
