#include "push_swap.h"

int	ft_check_croissant(t_pile *lst)
{
	t_pile	*temp_cmp;
	int		check;
	int		cmp;

	if (!lst)
		return (1);
	if (lst->next == NULL)
		return (1);
	temp_cmp = lst->next;
	while (lst->next != NULL)
	{
		check = lst->content;
		cmp = temp_cmp->content;
		if (check >= cmp)
			return (0);
		temp_cmp = temp_cmp->next;
		lst = lst->next;
		temp_cmp = lst->next;
	}
	return (1);
}

int	ft_if_sorted(t_pile *lst_a, t_pile *lst_b)
{
	if (!lst_a)
		return (0);
	if (ft_check_croissant(lst_a))
	{
		if (!lst_b)
			return (1);
	}
	return (0);
}

int	ft_compter_val(t_pile *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_compter_val_a(t_pile *lst_a, t_pile *lst_b)
{
	int	i;

	i = 0;
	if (!lst_a || lst_b)
		return (0);
	while (lst_a)
	{
		lst_a = lst_a->next;
		i++;
	}
	return (i);
}
