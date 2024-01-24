/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:30:27 by iescalon          #+#    #+#             */
/*   Updated: 2024/01/24 12:01:56 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0 && nbr != -2147483648)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	count = ft_countnbr(nbr);
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		count = 11;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	return (count);
}

int	ft_count_unsignednbr(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_put_unsignednbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		count = 1;
	}
	else
	{
		count = ft_count_unsignednbr(nbr);
	}
	if (nbr >= 10)
	{
		ft_put_unsignednbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	return (count);
}
