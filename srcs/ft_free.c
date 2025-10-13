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
