/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:25:52 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/20 12:24:32 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
**  Global array containing all built in functions and the corresponding string
**  in a simple struct.
*/

t_builtin  g_builtin[6];

/*
**  Initialize buit_in array and convert the shell environnement
**  into a list.
*/

t_list  *ft_initialize_built_in_env(char **env)
{
  t_list  *new;
  t_list  *tmp;
  int     i;

  new = NULL;
  if (env && env[0])
  {
    if (!(new = ft_lstnew(env[0], ft_strlen(env[0]) + 1)))
      exit(EXIT_FAILURE);
    tmp = new;
    ((char*)tmp->content)[ft_strlen(env[0])] = '\0';
    i = 0;
    while(env[++i])
    {
      if (!(tmp->next = ft_lstnew(env[i], ft_strlen(env[i]) + 1)))
        exit(EXIT_FAILURE);
      tmp = tmp->next;
      ((char*)tmp->content)[ft_strlen(env[i])] = '\0';
    }
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
  return(new);
}

int bltin_echo(char **arg, t_list **env)
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

int bltin_cd(char **arg, t_list **env)
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

int bltin_exit(char **arg, t_list **env)
{
  (void)arg;
  (void)env;
  exit(EXIT_SUCCESS);
}
