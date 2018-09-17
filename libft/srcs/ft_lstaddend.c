/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:51:24 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/17 13:55:09 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_lstaddend(t_list **list, t_list *new)
{
  t_list *tmp;

  if (*list == NULL)
  {
    *list = *new;
  }
  else
  {
    tmp = *list;
    if (tmp)
    {
      while(tmp->next)
      {
        tmp = tmp->next;
      }
      tmp->next = new;
    }
  }
}
