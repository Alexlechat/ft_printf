/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:24:22 by allefran          #+#    #+#             */
/*   Updated: 2024/12/04 10:28:25 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	size_t	len;

	if (fd < 0)
		return (0);
	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_putnbr_fd(nb / 10, fd);
	}
	len += ft_putchar_fd((nb % 10) + '0', fd);
	return (len);
}

size_t	ft_putnbr_u_fd(unsigned int n, int fd)
{
	size_t	len;

	if (fd < 0)
		return (0);
	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_u_fd(n / 10, fd);
	}
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}

size_t	ft_putnbr_hex_fd(unsigned int n, int fd)
{
	size_t		len;
	long		nb;
	static char	dictionary[17] = "0123456789abcdef";

	if (fd < 0)
		return (0);
	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 16)
	{
		len += ft_putnbr_hex_fd(nb / 16, fd);
	}
	len += ft_putchar_fd(dictionary[nb % 16], fd);
	return (len);
}

size_t	ft_putnbr_upper_hex_fd(unsigned int n, int fd)
{
	size_t		len;
	long		nb;
	static char	dictionary[17] = "0123456789ABCDEF";

	if (fd < 0)
		return (0);
	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 16)
	{
		len += ft_putnbr_upper_hex_fd(nb / 16, fd);
	}
	len += ft_putchar_fd(dictionary[nb % 16], fd);
	return (len);
}
