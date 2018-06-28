/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:27:24 by clanglai          #+#    #+#             */
/*   Updated: 2018/06/28 15:22:54 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Start : init child proc to start running the minishell
*/

int main(void) {
  int   i;
  // pid_t child_p;
  char  *line;
  char  **arg;

  while(1)
    while(get_next_line(0, &line))
    {
      ft_putstr("$> ");
      i = 0;
      if (line && ft_strlen(line))
      {
        ft_printf("\n RESULT = ");
        if (!(arg = ft_strsplit(line, ' ')))
          exit(EXIT_FAILURE);
        while(arg[i])
          ft_printf("%s \n", arg[i++]);
      }
    }
    ft_putstr("END\n");
    return(0);
}
