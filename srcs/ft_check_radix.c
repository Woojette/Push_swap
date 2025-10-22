#include "push_swap.h"

void	ft_radix(t_pile **lst_a, t_pile **lst_b)
{
	int	size;
	int	max;
	int	temp_max;
	int	bits_max;

	if (!lst_a || !(*lst_a))
		return ;
	size = ft_compter_val((*lst_a));
	max = ft_check_max((*lst_a));
	temp_max = max;
	bits_max = 1;
	while (temp_max > 0)
	{
		
	}
}
