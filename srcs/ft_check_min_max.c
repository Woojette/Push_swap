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
	int		temp;

	if (!lst)
		return (0);
	max = lst->next->index;
	while (lst->next)
	{
		n1 = lst->index;
		// ft_printf("n1 : %d, max : %d\n", n1, max);
		if (n1 > max)
		{
			// ft_printf("CHnge n1 : %d, max : %d\n", n1, max);
			temp = n1;
			n1 = max;
			max = temp;
		}
		lst = lst->next;
	}
	return (max);
}
