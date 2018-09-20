/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:12:27 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/20 12:06:26 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int bltin_setenv(char **arg, t_list **env)
{
  (void)arg;
  (void)env;
  return(1);
}

int bltin_unsetenv(char **arg, t_list **env)
{
  (void)arg;
  (void)env;
  return(1);
}

int bltin_env(char **arg, t_list **env)
{
  (void)arg;
  t_list *tmp;

  tmp = *env;

  while (tmp)
  {
    ft_putstr(tmp->content);
    write(1, "\n", 1);
    tmp = tmp->next;
  }
  return(1);
}
