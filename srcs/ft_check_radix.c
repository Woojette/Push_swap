#include "push_swap.h"

int	ft_compter_bits_max(t_pile *lst)
{
	int	max;
	int	temp_max;
	int	bits_max;

	if (!lst)
		return (0);
	max = ft_check_max_index(lst);
	// ft_printf("max index dans ft_compter_bits_max : %d\n", max);
	temp_max = max;
	bits_max = 0;
	while (temp_max > 1)
	{
		temp_max = max >> bits_max;
		bits_max++;
	}
	return (bits_max);
}

int	ft_check_ordre_inverse(t_pile *lst, int suffix)
{
	t_pile	*temp_lst;
	int		n1;
	int		repeter;

	if (!lst)
		return (0);
	temp_lst = lst;
	n1 = temp_lst->index;
	repeter = suffix - 1;
	while (suffix > 0)
	{
		temp_lst = lst;
		while (repeter > 0)
		{
			temp_lst = temp_lst->next;
			repeter--;
		}
		n1 = temp_lst->index;
		if ((n1 + 1) != suffix)
			return (0);
		suffix--;
		repeter = suffix -1;
	}
	return (1);
}

// void	ft_radix(t_pile **lst_a, t_pile **lst_b)
// {
// 	int	i;
// 	int	size;
// 	int	repeter;
// 	int	bits_max;
// 	int	suffix;

// 	if (!lst_a || !(*lst_a))
// 		return ;
// 	i = 0;
// 	size = ft_compter_val((*lst_a));
// 	repeter = 0;
// 	bits_max = ft_compter_bits_max((*lst_a));
// 	suffix = ft_check_max_index((*lst_a));
// 	suffix = ft_check_max_index((*lst_a));
// 	ft_printf("suffix : %d\n", suffix);
// 	ft_printf("bits max : %d\n", bits_max);
// 	ft_printf("size : %d\n",size);
// 	ft_printf("Initial lst_a et lst_b : \n");
// 	ft_print_deux_tout((*lst_a), (*lst_b));
// 	while (bits_max > i)
// 	{
// 		while (size > repeter)
// 		{
// 			if ((((*lst_a)->index) >> i) & 1)
// 				ft_rotate_a(&(*lst_a));
// 			else if (((((*lst_a)->index) >> i) & 1) == 0)
// 				ft_push_pb(lst_a, lst_b);
// 			repeter++;
// 		}
// 		while ((*lst_b))
// 			ft_push_pa(lst_a, lst_b);
// 		i++;
// 		repeter = 0;
// 	}
// }

void	ft_radix(t_pile **lst_a, t_pile **lst_b)
{
	int	position_bits;
	int	size;
	int	repeter;
	int	bits_max;
	int	suffix;
	int test_inverse;

	if (!lst_a || !(*lst_a))
		return ;
	position_bits = 0;
	size = ft_compter_val((*lst_a));
	repeter = 0;
	bits_max = ft_compter_bits_max((*lst_a));
	suffix = ft_check_max_index((*lst_a));
	test_inverse = -1;
	ft_printf("suffix : %d\n", suffix);
	ft_printf("bits max : %d\n", bits_max);
	ft_printf("size : %d\n",size);
	ft_printf("Initial lst_a et lst_b : \n");
	ft_print_deux_tout((*lst_a), (*lst_b));

	while (bits_max > position_bits)
	{
		ft_printf("------------------ position bits = %d ------------------\n", position_bits);
		while (size > repeter)
		{
			ft_printf("repeter : %d\n", repeter);
			ft_printf("index : %d\n", (*lst_a)->index);
			if ((((*lst_a)->index) >> position_bits) & 1)
			{
				ft_printf("[%d] -> ra\n", (*lst_a)->index);
				ft_rotate_a(&(*lst_a));
				ft_print_deux_tout((*lst_a), (*lst_b));
			}
			else if (((((*lst_a)->index) >> position_bits) & 1) == 0)
			{
				ft_printf("[%d] -> pb\n", (*lst_a)->index);
				ft_push_pb(lst_a, lst_b);
				ft_print_deux_tout((*lst_a), (*lst_b));
			}
			repeter++;
			ft_printf("---- fin repeter %d ----\n", repeter);
			test_inverse = ft_check_ordre_inverse((*lst_a), suffix);
			ft_printf("ordre A : %d\n", test_inverse);
				// break ;
		}
		while ((*lst_b))
			ft_push_pa(lst_a, lst_b);
		ft_printf("Après remise de B dans A : \n");
		ft_print_deux_tout((*lst_a), (*lst_b));
		position_bits++;
		repeter = 0;
	}
}

