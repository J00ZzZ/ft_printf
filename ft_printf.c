/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:14 by liyu-her          #+#    #+#             */
/*   Updated: 2024/01/31 17:05:42 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(va_list args, const char format)
{
	if (format == 'c')
		return (my_putchar(va_arg(args, int)));
	else if (format == '%')
		return (my_putchar('%'));
	else if (format == 's')
		return (my_string(va_arg(args, char *)));
	else if (format == 'i' || format == 'd')
		return (my_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (my_unputnbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (my_hexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (my_pointer(va_arg(args, void *)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_args(args, format[i + 1]);
			i++;
		}
		else
			len += my_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	void *i;
// // 	unsigned int	j;
// // 	// unsigned int	k;
// // 	// unsigned int	z;

// // 	j = 437461;
// // 	// k = 8008;
// // 	// z = 123567;
// 	ft_printf("Print: %p\n", &i);
// // 	printf("Printf: %x\n", j);
// // 	printf("Printf: %p\n", &i);
// // 	// ft_printf("Print %x\n", j);
// // 	// printf("Printf %x\n", j);
// // 	// ft_printf("Print %X\n", k);
// // 	// printf("Printf %X\n", k);
// // 	// ft_printf("Print %X\n", z);
// // 	// printf("Printf %X\n", z);
// }
