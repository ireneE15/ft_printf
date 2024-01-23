/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:21:00 by iescalon          #+#    #+#             */
/*   Updated: 2024/01/23 13:59:51 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_check(va_list args, char c)
{
	int i;

	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		i = ft_putchar('%');
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
		if (*s == '%')
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

int	main(void)
{
//	int				num = -9;
//	unsigned int	i = 5;
	char			s = 'c';
	char			*str = "Hola";
//	unsigned int	hx = 16;

	int a = ft_printf("string%%: %c %s\n", s, str);
	int b = printf("string%%: %c %s\n", s, str);
	printf("Valor Original = %d, valor mío = %d\n",a, b);
	return (0);
}
