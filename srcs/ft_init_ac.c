/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dans_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_pile **l_a, t_pile **l_b, t_pile **l_new, t_pile **cp_a)
{
	(*l_a) = NULL;
	(*l_b) = NULL;
	(*l_new) = NULL;
	(*cp_a) = NULL;
}

void	ft_init_ps(t_ps **ps)
{
	(*ps)->error = 0;
	(*ps)->arg = 1;
}

int	ft_ac_2(t_pile **lst_a, t_pile **l_new, t_ps **ps, char **av)
{
	(*ps)->arg = 0;
	(*ps)->av_splite = ft_split(av[1], ' ');
	while ((*ps)->av_splite[(*ps)->arg])
	{
		if (ft_check_av((*ps)->av_splite[(*ps)->arg], (*lst_a)) == 1)
		{
			ft_lst_clear(lst_a);
			ft_free_pl((*ps)->av_splite);
			(*ps)->av_splite = NULL;
			free((*ps));
			(*ps) = NULL;
			exit (1);
		}
		(*l_new) = ft_lstnew(ft_atoi((*ps)->av_splite[(*ps)->arg],
					&((*ps)->error)));
		ft_lstadd_back(lst_a, (*l_new));
		(*ps)->arg++;
	}
	ft_free_pl((*ps)->av_splite);
	(*ps)->av_splite = NULL;
	return (0);
}

int	ft_ac_pl(t_pile **lst_a, t_pile **lst_new, t_ps **ps, char **av)
{
	if (ft_check_av(av[(*ps)->arg], (*lst_a)) == 1)
	{
		ft_lst_clear(lst_a);
		free((*ps));
		(*ps) = NULL;
		exit (1);
	}
	(*lst_new) = ft_lstnew(ft_atoi(av[(*ps)->arg], &((*ps)->error)));
	ft_lstadd_back(lst_a, (*lst_new));
	(*ps)->arg++;
	return (0);
}
