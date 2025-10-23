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

int	ft_check_max(t_pile *lst)
{
	t_pile	*temp_lst;
	int		max;

	if (!lst)
		return (0);
	temp_lst = lst;
	max = 0;
	ft_bubble_sort(&lst);
	while (temp_lst->next)
	{
		temp_lst = temp_lst->next;
	}
	max = temp_lst->index;
	return (max);
}
