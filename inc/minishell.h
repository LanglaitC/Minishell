/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <clanglai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:41:41 by clanglai          #+#    #+#             */
/*   Updated: 2018/09/20 11:42:27 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/inc/libft.h"
# define BUILTIN_NUMBER 6

typedef struct  s_builtin {
  char          *label;
  int(*func)(char**, t_list**);
}               t_builtin;

extern   t_builtin  g_builtin[BUILTIN_NUMBER];

/*
** File: proc.c
*/

pid_t   ft_init_child_proc();
int     process_cmd(char **cmds, t_list **env_list);
int     process_line(char **cmds, t_list **env_list);
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
int     bltin_echo(char **arg, t_list **env_list);
int     bltin_cd(char **arg, t_list **env_list);
int     bltin_setenv(char **arg, t_list **env_list);
int     bltin_unsetenv(char **arg, t_list **env_list);
int     bltin_env(char **arg, t_list **env_list);
int     bltin_exit(char **arg, t_list **env_list);
#endif
