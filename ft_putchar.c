/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:40:04 by allefran          #+#    #+#             */
/*   Updated: 2024/12/04 09:59:32 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	size_t	len;

	len = 0;
	len = write(fd, &c, 1);
	return (len);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (!s)
	{
		len += write(fd, "(null)", 6);
		return (len);
	}
	while (s[i])
	{
		len += write(fd, &s[i], 1);
		i++;
	}
	return (len);
}
