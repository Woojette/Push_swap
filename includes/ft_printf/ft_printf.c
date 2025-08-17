/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:37:38 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:47:09 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_afficher(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	if (str[i + 1] == 's')
		count += ft_putstr(va_arg(args, char *));
	if (str[i + 1] == 'p')
		count += ft_putpointer(va_arg(args, void *));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (str[i + 1] == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	if (str[i + 1] == 'x')
		count += ft_putnbr_hexa_min(va_arg(args, unsigned int));
	if (str[i + 1] == 'X')
		count += ft_putnbr_hexa_max(va_arg(args, unsigned int));
	if (str[i + 1] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_afficher(str, i, args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{

	char *p = NULL;
	// int a = 123456;

	printf(" || byte:%d\n", ft_printf("%c %c %c",100, 'j', 'a'));
	printf(" || byte:%d\n", printf("%c %c %c",100, 'j', 'a'));

	write(1,"\n",1);
	printf(" || byte:%d\n", ft_printf("%s %s %s", "test", p, "bonjour"));
	printf(" || byte:%d (vrai)\n", printf("%s %s %s", "test", p, "bonjour"));

	write(1,"\n",1);
	printf(" || byte:%d\n", ft_printf("%p %p %p", "test", p, 123456));
	printf(" || byte:%d (vrai)\n", printf("%p %p %p", "test", p, (void *)123456));

	write(1,"\n",1);

	printf(" || byte:%d\n", ft_printf("%d %d %d",123, INT_MIN, 2147483647));
	printf(" || byte:%d\n", printf("%d %d %d",123, INT_MIN, 2147483647));

	write(1,"\n",1);

	printf(" || byte:%d\n", ft_printf("%i %i %i",123, INT_MIN, INT_MAX));
	printf(" || byte:%d\n", printf("%i %i %i",123, INT_MIN, INT_MAX));

	write(1,"\n",1);

	printf(" || byte:%d\n", ft_printf("%x %x %x",123, INT_MIN, INT_MAX));
	printf(" || byte:%d\n", printf("%x %x %x",123, INT_MIN, INT_MAX));

	write(1,"\n",1);

	printf(" || byte:%d\n", ft_printf("%X %X %X",123, INT_MIN, INT_MAX));
	printf(" || byte:%d\n", printf("%X %X %X",123, INT_MIN, INT_MAX));

	write(1,"\n",1);

	printf(" || byte:%d\n", ft_printf("%u %u %u",123, INT_MIN, INT_MAX));
	printf(" || byte:%d\n", printf("%u %u %u",123, INT_MIN, INT_MAX));

	write(1,"\n",1);

	printf("%d\n", ft_printf(NULL));
	printf("%d\n", printf(NULL));

	write(1,"\n",1);

}*/
