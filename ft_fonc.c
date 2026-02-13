/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:54:16 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/13 07:48:36 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptchar(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_ptstr(char *a)
{
	int	i;

	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (a[i] != '\0')
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_pthex_u(unsigned int a)
{
	char	*b;
	int		x;

	x = 0;
	b = "0123456789ABCDEF";
	if (a >= 16)
	{
		x += ft_pthex_u(a / 16);
		x += ft_pthex_u(a % 16);
	}
	else
	{
		x += write(1, &b[a / 16], 1);
		x += write(1, &b[a % 16], 1);
	}
	return (x);
}

int	ft_pthex_l(unsigned int a)
{
	char	*b;
	int		x;

	x = 0;
	b = "0123456789abcdef";
	if (a >= 16)
	{
		x += ft_pthex_l(a / 16);
		x += ft_pthex_l(a % 16);
	}
	else
	{
		x += write(1, &b[a / 16], 1);
		x += write(1, &b[a % 16], 1);
	}
	return (x);
}

int	ft_pthex_a(unsigned long a)
{
	char	*b;
	int		x;

	x = 0;
	b = "0123456789abcdef";
	if (a >= 16)
	{
		x += ft_pthex_l(a / 16);
		x += ft_pthex_l(a % 16);
	}
	else
	{
		x += write(1, &b[a / 16], 1);
		x += write(1, &b[a % 16], 1);
	}
	return (x);
}
