/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:35 by iescalon          #+#    #+#             */
/*   Updated: 2024/01/24 13:58:03 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int nbr, char c)
{
	int		count;
	char	hex;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16, c);
		nbr = nbr % 16;
	}
	if (nbr <= 9)
	{
		hex = (nbr + '0');
	}
	else
	{
		if (c == 'x')
			hex = nbr + 87;
		else
			hex = nbr + 55;
	}
	ft_putchar(hex);
	count++;
	return (count);
}
