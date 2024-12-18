/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:11:02 by allefran          #+#    #+#             */
/*   Updated: 2024/12/05 14:36:46 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_format_specifier(char specifier, va_list arg_list, int fd)
{
	size_t	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar_fd(((char)va_arg(arg_list, int)), fd);
	else if (specifier == 's')
		len += ft_putstr_fd(((char *)va_arg(arg_list, const char *)),
				fd);
	else if (specifier == 'p')
		len += ft_putptr_fd(((char *)va_arg(arg_list, const char *)),
				fd);
	else if (specifier == 'd')
		len += ft_putnbr_fd(va_arg(arg_list, int), fd);
	else if (specifier == 'i')
		len += ft_putnbr_fd(va_arg(arg_list, int), fd);
	else if (specifier == 'u')
		len += ft_putnbr_u_fd(va_arg(arg_list, unsigned int), fd);
	else if (specifier == 'x')
		len += ft_putnbr_hex_fd(va_arg(arg_list, int), fd);
	else if (specifier == 'X')
		len += ft_putnbr_upper_hex_fd(va_arg(arg_list, int), fd);
	else if (specifier == '%')
		len += write(1, "%%", fd);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	arg_list;
	int		fd;

	if (!format)
		return (-1);
	va_start(arg_list, format);
	fd = 1;
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len += ft_putchar_fd(format[i], fd);
		if (format[i] == '%')
		{
			i++;
			len += ft_format_specifier(format[i], arg_list, fd);
		}
		i++;
		va_end(arg_list);
	}
	return ((int)len);
}

// int	main(void)
// {
// 	char			string[] = "char: %c\n\
// 								string: %s\n\
// 								pointer: %p\n\
// 								decimal: %d\n\
// 								integer: %i\n\
// 								unsigned int: %u\n\
// 								hexadecimal: %x\n\
// 								HEXADECIMAL: %X\n\
// 								purcent: %%\n";
// 	int				len;
// 	char			test_char;
// 	char			test_string[] = "alexandre";
// 	char			*test_pointeur;
// 	int				test_decimal;
// 	int				test_integer;
// 	unsigned int	test_unsigned_int;
// 	int				test_hexadecimal;
// 	int				test_HEXADECIMAL;
// 	char			test_purcent;

// 	test_char = 'a';
// 	test_pointeur = &test_char;
// 	test_decimal = 42;
// 	test_integer = 43;
// 	test_unsigned_int = 44;
// 	test_hexadecimal = 166;
// 	test_HEXADECIMAL = 166;
// 	test_purcent = '%';

// 	len = ft_printf(string, 
// 			test_char, test_string, test_pointeur, test_decimal,
// 			test_integer, test_unsigned_int, test_hexadecimal, test_HEXADECIMAL,
// 			test_purcent);
// 	ft_printf("***null: \n", NULL);
// 	printf("len: %d", len);
// int len = 0;
// printf("%d\n", ft_printf(0));
// printf("%d", printf(0));
// printf("\nlen: %d\n", len);
// len = printf("0");
// printf("\nlen: %d\n", len);
// 	return (0);
// }
