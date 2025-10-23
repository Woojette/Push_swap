#include "push_swap.h"

int	ft_compter_bits_max(t_pile *lst)
{
	int	max;
	int	temp_max;
	int	bits_max;

	if (!lst)
		return (0);
	max = ft_check_max(lst);
	temp_max = max;
	bits_max = 0;
	while (temp_max > 0)
	{
		temp_max = max >> bits_max;
		bits_max++;
	}
	return (bits_max);
}

void	ft_radix(t_pile **lst_a, t_pile **lst_b)
{
	t_pile	*temp_lst_a;
	int		i;
	int		size;
	int		repeter;
	int		bits_max;

	if (!lst_a || !(*lst_a))
		return ;
	i = 0;
	size = ft_compter_val((*lst_a));
	repeter = 0;
	bits_max = ft_compter_bits_max((*lst_a));
	ft_printf("\n bits max : %d\n", bits_max);
	temp_lst_a = (*lst_a);
	ft_printf("\nsize : %d\n",size);
	while (bits_max > i)
	{
		while (size > repeter)
		{
			if ((((*lst_a)->index) >> i) & 1)
				ft_rotate_a(&(*lst_a));
			else if ((((*lst_a)->index) >> i) & 0)
				ft_push_pb(lst_a, lst_b);
			repeter++;
		}
		i++;
		repeter = 0;
		ft_printf("i %d | ", i);
	}
}
