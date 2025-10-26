/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **resultat, int j)
{
	if (!resultat)
		return ;
	while (j > 0)
	{
		j--;
		if (resultat[j])
		{
			free(resultat[j]);
			resultat[j] = NULL;
		}
	}
	free(resultat);
}

void	ft_free_pl(char **resultat)
{
	int	i;

	if (!resultat || !*resultat)
		return ;
	i = 0;
	while (resultat[i])
	{
		if (resultat[i])
		{
			free(resultat[i]);
			resultat[i] = NULL;
		}
		i++;
	}
	free(resultat);
}

void	ft_lst_clear(t_pile **lst)
{
	t_pile	*temp;

	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
}

void	ft_free_list(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac)
{
	if (lst_a)
		ft_lst_clear(lst_a);
	if (lst_b)
		ft_lst_clear(lst_b);
	if (ps && *ps)
	{
		if (ac == 2 && (*ps)->av_splite)
			ft_free_pl((*ps)->av_splite);
		free(*ps);
		*ps = NULL;
	}
}
