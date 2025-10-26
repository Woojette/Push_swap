/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:21:08 by wooyang           #+#    #+#             */
/*   Updated: 2025/10/25 21:21:12 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_ps
{
	int		arg;
	int		arg2;
	int		error;
	int		atoi_av1;
	char	**av_splite;
}	t_ps;

typedef struct s_pile
{
	int				content;
	int				index;
	struct s_pile	*next;
}	t_pile;

t_pile	*ft_lstnew(int content);
void	ft_lstadd_front(t_pile **list, t_pile *new);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
t_pile	*ft_lstmap(t_pile *lst, int (*f)(t_pile *lst), void (*del)(void *));
void	ft_lst_clear(t_pile **lst);
void	ft_free(char **resultat, int j);
void	ft_free_pl(char **resultat);
void	ft_free_list(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac);
int		ft_int_check(char *av);
int		ft_limit_check(char *av);
int		ft_dup_check(char *av, t_pile *lst);
int		ft_tablen(char **tab);
int		ft_check_av(char *av, t_pile *lst);
int		ft_check_croissant(t_pile *lst);
void	ft_print_list(t_pile *lst);
void	ft_print_deux_content(t_pile *list_a, t_pile *list_b);
void	ft_print_deux_tout(t_pile *list_a, t_pile *list_b);
void	ft_swap(t_pile **lst);
void	ft_swap_a(t_pile **lst);
void	ft_swap_b(t_pile **lst);
void	ft_swap_ss(t_pile **lst_a, t_pile **lst_b);
void	ft_rotate(t_pile **lst);
void	ft_rotate_a(t_pile **lst);
void	ft_rotate_b(t_pile **lst);
void	ft_rotate_rr(t_pile **lst_a, t_pile **lst_b);
void	ft_rv_rotate(t_pile **lst);
void	ft_rv_rotate_a(t_pile **lst);
void	ft_rv_rotate_b(t_pile **lst);
void	ft_rv_rotate_rrr(t_pile **lst_a, t_pile **lst_b);
void	ft_push_pb(t_pile **lst_a, t_pile **lst_b);
void	ft_push_pa(t_pile **lst_a, t_pile **lst_b);
int		ft_if_sorted(t_pile *lst_a, t_pile *lst_b);
int		ft_compter_val(t_pile *lst);
int		ft_compter_val_a(t_pile *lst_a, t_pile *lst_b);
void	ft_check_val_a_123(t_pile **lst);
void	ft_check_val_a_2(t_pile **lst);
void	ft_check_val_a_3(t_pile **lst);
void	ft_tri_a_3(int n1, int n2, int n3, t_pile **lst);
void	ft_check_val_4(t_pile **lst_a, t_pile **lst_b);
int		ft_check_min(t_pile *lst);
int		ft_check_val_4_pb_0(t_pile *lst);
void	ft_val_4_pb_0(t_pile **lst_a);
void	ft_min_push_4(t_pile **lst_a, t_pile **lst_b, int min);
int		ft_list_contenu_copie(t_pile *lst);
void	ft_bubble_sort(t_pile **lst);
void	ft_bubble_sort_index(t_pile **lst);
void	ft_swap_int(int *n1, int *n2);
void	ft_index(t_pile **lst);
void	ft_index_copie(t_pile **lst, t_pile **copie);
void	ft_index_radix(t_pile **lst_a, t_pile **lst_b, t_pile **copie_a);
void	ft_radix(t_pile **lst_a, t_pile **lst_b);
int		ft_check_max_index(t_pile *lst);
int		ft_compter_bits_max(t_pile *lst);
void	ft_check_position_bits(t_pile **lst_a, t_pile **lst_b, int p_bits);
void	ft_init(t_pile **l_a, t_pile **l_b, t_pile **l_new, t_pile **cp_a);
int		ft_check_sorted_1234(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac);
int		ft_ac_2(t_pile **lst_a, t_pile **l_new, t_ps **ps, char **av);
int		ft_ac_pl(t_pile **lst_a, t_pile **lst_new, t_ps **ps, char **av);

#endif
