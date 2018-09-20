/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:27:24 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/20 11:35:20 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Start : Loop to read input and parse it each time the user press enter.
**  envp is the shell's env.
*/

int main(int argc, char **argv, char **envp) {
  char    *line;
  char    **cmds;
  t_list  *hist;
  t_list  *env_list;

  (void)argc;
  (void)argv;
  hist = NULL;
  ft_putstr("$> ");
  env_list = ft_initialize_built_in_env(envp);
  while(1)
    while(get_next_line(0, &line))
    {
      if (line && ft_strlen(line))
      {
        save_cmd(&hist, line);
        if (!(cmds = ft_strsplit(line, ';')))
          exit(EXIT_FAILURE);
        process_line(cmds, &env_list);
      }
      ft_putstr("$> ");
    }
  return(0);
}
