# include <stdarg.h>
# include <unistd.h>

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_string(char *c)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, c, my_strlen(c));
	return (my_strlen(c));
}

int	my_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	my_putnbr(int nb)
{
	int		i;
	long	longnb;

	longnb = (long)nb;
	i = 0;
	if (longnb < 0)
	{
		i += my_putchar('-');
		longnb *= -1;
	}
	if (longnb >= 10)
	{
		i += my_putnbr(longnb / 10);
		i += my_putnbr(longnb % 10);
	}
	if (longnb >= 0 && longnb <= 9)
	{
		i += my_putchar(longnb + 48);
	}
	return (i);
}

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

int	ft_args(va_list args, const char format)
{
	if (format == 's')
		return (my_string(va_arg(args, char *)));
	else if (format == 'd')
		return (my_putnbr(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (my_hexa(va_arg(args, unsigned int), format));
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