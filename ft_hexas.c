/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:00 by liyu-her          #+#    #+#             */
/*   Updated: 2024/01/31 17:06:14 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_hexa(unsigned long nb, char c)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += my_hexa(nb / 16, c);
		i += my_hexa(nb % 16, c);
	}
	else
	{
		if (nb >= 10 && nb <= 15)
		{
			if (c == 'x')
				i += my_putchar(nb + 'a' - 10);
			else if (c == 'X')
				i += my_putchar(nb + 'A' - 10);
		}
		else
			i += my_putchar(nb + 48);
	}
	return (i);
}

int	my_pointer(void *n)
{
	int	i;

	my_string("0x");
	i = 2;
	if (!n)
	{
		i += write(1, "0", 1);
		return (i);
	}
	i += my_hexa((unsigned long long)n, 'x');
	return (i);
}
