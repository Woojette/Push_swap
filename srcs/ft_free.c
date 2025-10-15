#include "push_swap.h"

void	ft_free(char **resultat, int j)
{
	while (j > 0)
	{
		j--;
		free(resultat[j]);
	}
	free(resultat);
}

void	ft_lst_clear(t_pile **lst)
{
	t_pile	*temp;

	if (!(*lst))
		return ;
	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}

void	ft_free_list(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac)
{
	ft_lst_clear(lst_a);
	ft_lst_clear(lst_b);
	if (ac == 2)
		ft_free((*ps)->av_splite, (*ps)->arg);
	free(*ps);
}
