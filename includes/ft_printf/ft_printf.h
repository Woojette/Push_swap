/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:47:57 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/28 17:50:08 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr_hexa_min(unsigned int n);
int	ft_putnbr_hexa_max(unsigned int n);
int	ft_putpointer(void *n);
int	ft_printf(const char *str, ...);

#endif
