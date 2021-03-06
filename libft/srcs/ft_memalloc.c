/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:53:42 by clanglai          #+#    #+#             */
/*   Updated: 2018/05/15 15:30:47 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	(void)size;
	if (!(memory = malloc(sizeof(void) * size)))
		return (NULL);
	while (i < size)
	{
		((char*)memory)[i] = 0;
		i++;
	}
	return (memory);
}
