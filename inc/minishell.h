/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:41:41 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/17 13:33:14 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/inc/libft.h"
# define BUILTIN_NUMBER 6

typedef struct  s_builtin {
  char          *label;
  int(*func)(char**, char**);
}               t_builtin;

extern   t_builtin  g_builtin[BUILTIN_NUMBER];

/*
** File: proc.c
*/

pid_t   ft_init_child_proc();
int     process_cmd(char **cmds, char **envp);
int     process_line(char **cmds, char **envp);
/*
** File: get_args.c
*/

/*
** File: save_cmd.c
*/
void    save_cmd(t_list **list, char *cmd);
/*
** File: built_in.c
*/
t_list  *ft_initialize_built_in_env(char **envp);
int     bltin_echo(char **arg, char **env);
int     bltin_cd(char **arg, char **env);
int     bltin_setenv(char **arg, char **env);
int     bltin_unsetenv(char **arg, char **env);
int     bltin_env(char **arg, char **env);
int     bltin_exit(char **arg, char **env);
#endif
