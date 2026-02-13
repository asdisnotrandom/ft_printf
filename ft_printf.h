/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:27:14 by ademirel          #+#    #+#             */
/*   Updated: 2026/02/13 07:41:50 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_ptchar(int a);
int	ft_ptstr(char *a);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_pthex_u(unsigned int a);
int	ft_pthex_l(unsigned int a);
int	ft_pthex_a(unsigned long a);
int	ft_pthex_p(void *c);

#endif