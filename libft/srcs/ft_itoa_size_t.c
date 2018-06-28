/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:10:55 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/15 13:17:30 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>

static int	ft_guess_power(ssize_t n)
{
	__int128			i;
	int					j;

	j = 1;
	i = 1;
	while (n / (10 * i) != 0)
	{
		i = i * 10;
		j++;
	}
	return (j);
}

static char	*ft_itoa_neg(char *str, ssize_t n, int power)
{
	int	i;

	if (!(str = malloc(sizeof(char) * power + 2)))
		return (NULL);
	i = power;
	str[power + 1] = '\0';
	str[0] = '-';
	while (i > 0)
	{
		str[i] = (-(n % 10) + '0');
		n = n / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa_size_t(ssize_t n)
{
	int		i;
	int		power;
	char	*str;

	str = NULL;
	power = ft_guess_power(n);
	if (n < 0)
	{
		str = ft_itoa_neg(str, n, power);
		return (str);
	}
	if (!(str = malloc(sizeof(char) * power + 1)))
		return (NULL);
	i = power - 1;
	str[power] = '\0';
	while (i >= 0)
	{
		str[i] = (n % 10 + '0');
		n = n / 10;
		i--;
	}
	return (str);
}
