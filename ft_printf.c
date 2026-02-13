/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:48:42 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/13 09:50:06 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mixer(int a, va_list arg)
{
	int	count;

	count = 0;
	if (a == 'c')
		count += ft_ptchar(va_arg(arg, int));
	else if (a == 's')
		count += ft_ptstr(va_arg(arg, char *));
	else if (a == 'p')
		count += ft_pthex_p(va_arg(arg, void *));
	else if (a == 'd' || a == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (a == 'u')
		count += ft_putnbr_u(va_arg(arg, unsigned int));
	else if (a == 'x')
		count += ft_pthex_l(va_arg(arg, unsigned int));
	else if (a == 'X')
		count += ft_pthex_u(va_arg(arg, unsigned int));
	else if (a == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		a;
	va_list	args;

	count = 0;
	if (format == 0)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			a = ft_mixer(*(format + 1), args);
			if (a == -1)
				return (va_end(args), -1);
			count += a;
			format += 2;
		}
		else
			count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}
