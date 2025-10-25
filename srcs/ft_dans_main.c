#include "push_swap.h"

int	ft_check_sorted_1234(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac)
{
	if (ft_if_sorted((*lst_a), (*lst_b)))
		return (ft_free_list(lst_a, lst_b, ps, ac), 0);
	if (ft_compter_val_a((*lst_a), (*lst_b)) <= 3)
		return (ft_check_val_a_123(lst_a), ft_free_list(lst_a, lst_b, ps, ac), 0);
	if (ft_compter_val_a((*lst_a), (*lst_b)) == 4)
		return (ft_check_val_4(lst_a, lst_b), ft_free_list(lst_a, lst_b, ps, ac), 0);
	return (0);
}

void	ft_index_radix(t_pile **lst_a, t_pile **lst_b, t_pile **copie_a)
{
	(*copie_a) = ft_lstmap((*lst_a), ft_list_contenu_copie, free);
	ft_bubble_sort(copie_a);
	ft_index(copie_a);
	ft_index_copie(lst_a, copie_a);
	ft_radix(lst_a, lst_b);
}
