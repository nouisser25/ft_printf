/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouisse <anouisse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:58:50 by anouisse          #+#    #+#             */
/*   Updated: 2026/11/27 16:26:26 by anouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	if (!*str)
		return (write(1, "", 0));
	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		len;
	int		res;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		res = ft_putnbr(nb / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 10)
	{
		res = ft_putnbr_unsigned(n / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_puthex(unsigned int n, const char format)
{
	int		len;
	int		res;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		res = ft_puthex(n / 16, format);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (len + 1);
}
