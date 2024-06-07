/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:30 by liyu-her          #+#    #+#             */
/*   Updated: 2024/01/31 17:59:57 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_args(va_list args, const char format);
int	my_strlen(const char *str);
int	my_string(char *c);
int	my_putchar(char c);
int	my_putnbr(int nb);
int	my_unputnbr(unsigned int nb);
int	my_hexa(unsigned long nb, char c);
int	my_pointer(void *n);

#endif