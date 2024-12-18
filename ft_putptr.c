/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:38:21 by allefran          #+#    #+#             */
/*   Updated: 2024/12/04 10:27:04 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putptr_hex_fd(uintptr_t n, int fd)
{
	size_t		len;
	static char	dictionary[17] = "0123456789abcdef";

	if (fd < 0)
		return (0);
	len = 0;
	if (n >= 16)
	{
		len += ft_putptr_hex_fd(n / 16, fd);
	}
	len += ft_putchar_fd(dictionary[n % 16], fd);
	return (len);
}

size_t	ft_putptr_fd(void *ptr, int fd)
{
	size_t		i;
	size_t		len;
	uintptr_t	address;

	len = 0;
	i = 0;
	address = (uintptr_t)ptr;
	if (!ptr)
	{
		len += write(fd, "(nil)", 5);
		return (len);
	}
	len += write(fd, "0x", 2);
	len += ft_putptr_hex_fd(address, 1);
	return (len);
}
