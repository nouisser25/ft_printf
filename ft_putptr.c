/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouisse <anouisse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:58:46 by anouisse          #+#    #+#             */
/*   Updated: 2026/11/27 16:26:34 by anouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long n)
{
	int		len;
	int		res;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		res = ft_puthex_ptr(n / 16);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int				len;
	int				res;
	unsigned long	addr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len = ft_putstr("0x");
	if (len == -1)
		return (-1);
	res = ft_puthex_ptr(addr);
	if (res == -1)
		return (-1);
	return (len + res);
}
