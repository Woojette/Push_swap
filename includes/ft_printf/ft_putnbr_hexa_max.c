/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:42:33 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:42:49 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_max(unsigned int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb > 15)
		i += ft_putnbr_hexa_max(nb / 16);
	i += write(1, &"0123456789ABCDEF"[nb % 16], 1);
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
