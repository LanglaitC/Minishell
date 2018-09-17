/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:25:52 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/17 13:50:24 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Global array containing all built in functions and the corresponding string
**  in a simple struct.
*/

t_builtin  g_builtin[6];

/*
**  Initialize buit_in array.
*/

t_list  *ft_initialize_built_in(char **env)
{
  t_list  *new;
  int     i;

  if (env && env[0])
  {
    t_list =
  }
  g_builtin[0].label = "echo";
  g_builtin[1].label = "cd";
  g_builtin[2].label = "setenv";
  g_builtin[3].label = "unsetenv";
  g_builtin[4].label = "env";
  g_builtin[5].label = "exit";
  g_builtin[0].func = &bltin_echo;
  g_builtin[1].func = &bltin_cd;
  g_builtin[2].func = &bltin_setenv;
  g_builtin[3].func = &bltin_unsetenv;
  g_builtin[4].func = &bltin_env;
  g_builtin[5].func = &bltin_exit;
}

int bltin_echo(char **arg, char **env)
{
  int i;

  (void)env;
  i = -1;
  if (arg == NULL || *arg == NULL || ft_strlen(*arg) == 0)
    return(0);
  else
    while(arg[++i])
      ft_putstr(arg[i]);
  return(1);
}

int bltin_cd(char **arg, char **env)
{
  int i;

  i = -1;
  (void)env;
  if (arg == NULL || *arg == NULL || ft_strlen(*arg) == 0)
   return(0);
  else
  {
    if (access(arg[0], X_OK) < 0)
      return(0);
    else
    {
      if(chdir(arg[0]) < 0)
        return(0);
      else
        return(1);
    }
  }
}

int bltin_exit(char **arg, char **env)
{
  (void)arg;
  (void)env;
  exit(EXIT_SUCCESS);
}
