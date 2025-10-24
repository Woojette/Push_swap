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

void	ft_radix(t_pile **lst_a, t_pile **lst_b)
{
	int	i;
	int	size;
	int	repeter;
	int	bits_max;

	if (!lst_a || !(*lst_a))
		return ;
	i = 0;
	size = ft_compter_val((*lst_a));
	repeter = 0;
	bits_max = ft_compter_bits_max((*lst_a));
	while (bits_max > i)
	{
		while (size > repeter)
		{
			if ((((*lst_a)->index) >> i) & 1)
				ft_rotate_a(&(*lst_a));
			else if (((((*lst_a)->index) >> i) & 1) == 0)
				ft_push_pb(lst_a, lst_b);
			repeter++;
		}
		while ((*lst_b))
			ft_push_pa(lst_a, lst_b);
		i++;
		repeter = 0;
	}
}

// void	ft_radix(t_pile **lst_a, t_pile **lst_b)
// {
// 	int	i;
// 	int	size;
// 	int	repeter;
// 	int	bits_max;

// 	if (!lst_a || !(*lst_a))
// 		return ;
// 	i = 0;
// 	size = ft_compter_val((*lst_a));
// 	repeter = 0;
// 	bits_max = ft_compter_bits_max((*lst_a));
// 	// ft_printf("bits max : %d\n", bits_max);
// 	// ft_printf("size : %d\n",size);
// 	// ft_printf("Initial lst_a et lst_b : \n");
// 	// ft_print_deux_tout((*lst_a), (*lst_b));

// 	while (bits_max > i)
// 	{
// 		// ft_printf("----- i = %d -----\n", i);
// 		while (size > repeter)
// 		{
// 			// ft_printf("repeter : %d\n", repeter);
// 			// ft_printf("index : %d\n", (*lst_a)->index);
// 			if ((((*lst_a)->index) >> i) & 1)
// 			{
// 				// ft_printf("[%d] -> ra\n", (*lst_a)->index);
// 				ft_rotate_a(&(*lst_a));
// 				// ft_print_deux_tout((*lst_a), (*lst_b));
// 			}
// 			else if (((((*lst_a)->index) >> i) & 1) == 0)
// 			{
// 				// ft_printf("[%d] -> pb\n", (*lst_a)->index);
// 				ft_push_pb(lst_a, lst_b);
// 				// ft_print_deux_tout((*lst_a), (*lst_b));
// 			}
// 			repeter++;
// 			// ft_printf("---- fin repeter %d ----\n", repeter);
// 		}
// 		while ((*lst_b))
// 			ft_push_pa(lst_a, lst_b);
// 		// ft_printf("Après remise de B dans A : \n");
// 		// ft_print_deux_tout((*lst_a), (*lst_b));
// 		i++;
// 		repeter = 0;
// 		// ft_printf("i %d | ", i);
// 	}
// }
