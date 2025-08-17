/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:38:34 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:40:36 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
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
/*
int	main (void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(221);
	write(1, "\n", 1);
	ft_putnbr(-71);
	return (0);
}*/
