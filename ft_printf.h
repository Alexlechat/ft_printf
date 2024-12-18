/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:50:36 by allefran          #+#    #+#             */
/*   Updated: 2024/12/04 09:59:03 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putnbr_u_fd(unsigned int n, int fd);
size_t	ft_putnbr_hex_fd(unsigned int n, int fd);
size_t	ft_putnbr_upper_hex_fd(unsigned int n, int fd);
size_t	ft_putptr_fd(void *ptr, int fd);
int		ft_printf(const char *format, ...);

#endif