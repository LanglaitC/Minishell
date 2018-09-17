/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:49:54 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/17 13:16:50 by clanglai         ###   ########.fr       */
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
  return(child_id);
}

/*
**  Execute the cmd, redirecting to builtin function or bin depending
**  the first argument of the given tab (command line split by whitespaces)
*/

int process_cmd(char **cmds, char **envp)
{
  int i;
  //pid_t child_proc;

  (void)envp;
  i = 0;
  //child_proc = ft_init_proc();
  while (i < BUILTIN_NUMBER)
  {
    if (ft_strequ(g_builtin[i].label, cmds[0]))
    {
      g_builtin[i].func(cmds, envp);
      return(1);
    }
    i++;
  }
  return (1);
}

/*
**  Receive the seperated cmd and process them one by one
*/

int process_line(char **cmds, char **envp)
{
  int i;
  char **args;

  i = 0;
  while (cmds[i])
  {
    if (!(args = ft_strsplit(cmds[i], ' ')))
      exit(EXIT_FAILURE);
    process_cmd(args, envp);
    i++;
  }
  ft_printf("Nombre d'arguments : %d\n", i);
  return (1);
}
