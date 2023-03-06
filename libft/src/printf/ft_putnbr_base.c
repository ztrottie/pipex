/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 16:57:01 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char maj)
{
	unsigned int	nb;
	char			*hexa;

	if (maj == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / ft_strlen(hexa) != 0)
		ft_putnbr_base((nb / ft_strlen(hexa)), maj);
	ft_putchar_fd(hexa[nb % ft_strlen(hexa)], 1);
	return (ft_hexa_len(nbr));
}
