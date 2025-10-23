#include "push_swap.h"

int	ft_list_contenu_copie(t_pile *lst)
{
  if (!lst)
    return (0);
	return (lst->content);
}

void	ft_swap_int(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	ft_bubble_sort(t_pile **lst)
{
	t_pile	*temp_lst;
	int		swap;
	int		swap_total;

	if (!lst || !(*lst))
		return ;
	swap = 1;
	swap_total = swap;
	while (swap_total)
	{
		temp_lst = (*lst);
		while (temp_lst->next)
		{
			if ((temp_lst->content) > (temp_lst->next->content))
			{
				ft_swap_int(&(temp_lst->content), &(temp_lst->next->content));
				swap++;
			}
			temp_lst = temp_lst->next;
		}
		swap_total = swap;
		swap = 0;
	}
}

void	ft_bubble_sort_index(t_pile **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_bubble_sort(lst);
	ft_index(lst);
}

void	ft_swap_valeurs(t_pile *lst_a, t_pile *lst_b)
{
	int	temp_content_a;
	int	temp_index_a;

	if (!lst_a || !lst_b)
		return ;
	temp_content_a = lst_a->content;
	temp_index_a = lst_a->index;
	lst_a->content = lst_b->content;
	lst_a->index = lst_b->index;
	lst_b->content = temp_content_a;
	lst_b->index = temp_index_a;
}
