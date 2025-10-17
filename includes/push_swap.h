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
	int		content;
	struct s_pile	*next;
}	t_pile;

t_pile	*ft_lstnew(int	content);
void	ft_lstadd_front(t_pile **list, t_pile *new);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
void	ft_lst_clear(t_pile **lst);
void	ft_free(char **resultat, int j);
void	ft_free_list(t_pile **lst_a, t_pile **lst_b, t_ps **ps, int ac);

int		ft_int_check(char *av);
int		ft_limit_check(char *av);
int		ft_dup_check(char *av, t_pile *lst);
int		ft_check_av(char *av, t_pile *lst);
int		ft_check_croissant(t_pile *lst);
void	ft_print_list(t_pile *list);
void	ft_print_deux(t_pile *list_a, t_pile *list_b);

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
int 	ft_check_2134(t_pile *lst);
void	ft_min_push(t_pile **lst_a, t_pile **lst_b, int min);

#endif
