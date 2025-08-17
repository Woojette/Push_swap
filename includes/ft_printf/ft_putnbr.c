/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:41:37 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/27 16:44:19 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

int	ft_putnbr(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		i++;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

// int	main (void)
// {
// 	// ft_putnbr(-2147483648);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(221);
// 	// write(1, "\n", 1);
// 	// ft_putnbr(-71);
// 	printf(" byte%d\n", printf("%d", INT_MIN));
// 	printf(" byte%d\n", ft_putnbr(-2147483648));
// 	return (0);
// }
