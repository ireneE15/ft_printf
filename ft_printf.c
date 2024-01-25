/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:21:00 by iescalon          #+#    #+#             */
/*   Updated: 2024/01/25 11:55:33 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		i = ft_putchar('%');
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i = ft_put_unsignednbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		i = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i = ft_putptr(va_arg(args, unsigned long int));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *s + 1)
		{
			len += ft_check(args, *(++s));
		}
		else
		{
			ft_putchar(*s);
			len++;
		}
		s++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int				num = -987;
	unsigned int	i = -455;
	char			s = 'c';
	char			*str = "Hello";
	unsigned int	hx = 16;
	int				a;
	int				b;

	a = ft_printf("str%%: %d %u %c %s %x %X %p\n", num, i, s, str, hx, hx, "");
	b = printf("str%%: %d %u %c %s %x %X %p\n", num, i, s, str, hx, hx, "");
	printf("Valor Original = %d, valor mío = %d\n", a, b);
	return (0);
}
*/
