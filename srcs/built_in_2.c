/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:12:27 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/17 13:02:05 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int bltin_setenv(char **arg, char **env)
{
  (void)arg;
  (void)env;
  return(1);
}

int bltin_unsetenv(char **arg, char **env)
{
  (void)arg;
  (void)env;
  return(1);
}

int bltin_env(char **arg, char **env)
{
  (void)arg;
  (void)env;
  return(1);
}
