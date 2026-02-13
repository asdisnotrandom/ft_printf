/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:39:55 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/13 07:49:22 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	z;
	long	x;
	int		i;

	i = 0;
	x = n;
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
		i++;
	}
	if (x >= 10)
	{
		i += ft_putnbr(x / 10);
		i += ft_putnbr(x % 10);
	}
	else if (x < 10)
	{
		z = (x % 10) + '0';
		write(1, &z, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	char			z;
	unsigned long	x;
	int				i;

	i = 0;
	x = n;
	if (x >= 10)
	{
		i += ft_putnbr_u(x / 10);
		i += ft_putnbr_u(x % 10);
	}
	else if (x < 10)
	{
		z = (x % 10) + '0';
		write(1, &z, 1);
		i++;
	}
	return (i);
}

int	ft_pthex_p(void *c)
{
	unsigned long	a;
	int				x;

	if (c == NULL)
		return (write(1, "(nil)", 5));
	x = 0;
	a = (unsigned long)c;
	x += write(1, "0x", 2);
	x += ft_pthex_a(a);
	return (x);
}
