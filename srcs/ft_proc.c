/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:49:54 by clanglai          #+#    #+#             */
/*   Updated: 2018/06/28 15:15:48 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Init child proc to run minishell
*/

pid_t ft_init_proc() {
  pid_t child_id;

  child_id = fork();
  if (child_id < 0)
  {
    perror("");
    exit(EXIT_FAILURE);
  }
  else
  {
    return(child_id);
  }
  return(child_id);
}
