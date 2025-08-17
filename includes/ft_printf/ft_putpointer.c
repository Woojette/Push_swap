/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:44:51 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:44:53 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int		i;

	i = 0;
	if (n > 15)
		i += ft_putptr(n / 16);
	i += write(1, &"0123456789abcdef"[n % 16], 1);
	return (i);
}

int	ft_putpointer(void *n)
{
	int	i;

	i = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 2;
	i += ft_putptr((unsigned long)n);
	return (i);
}

// int main()
// {
//     // char *test = "Bonjour";
//     char *test = NULL;
//     ft_putpointer(test);
// 	write(1,"\n",1);
//     printf("%p\n\n", INT_MIN);

//     // test = "123456789132465789";
//     // ft_putpointer(test);
// 	// write(1,"\n",1);
//     // printf("%p\n\n", test);

//     // test = "abcdefiopioipoiipoip";
//     // ft_putpointer(test);
// 	// write(1,"\n",1);
//     // printf("%p\n\n", test);
// }
