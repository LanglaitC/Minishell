/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:30:06 by clanglai          #+#    #+#             */
/*   Updated: 2018/08/30 11:37:42 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Save the command to add and add it to the existing command history
*/

void save_cmd(t_list **list, char *new)
{
  t_list *tmp;

  if (*list == NULL)
  {
      if (!(*list = ft_lstnew(new, ft_strlen(new) + 1)))
        exit(EXIT_FAILURE);
  }
  else
  {
      if (!(tmp = ft_lstnew(new, ft_strlen(new) + 1)))
        exit(EXIT_FAILURE);
      tmp->next = *list;
      *list = tmp;
  }
}
