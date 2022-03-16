/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:28 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:17:14 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SHELL_H
# define MY_SHELL_H

# include "libft.h"
# include "my_structures.h"

# include <printf.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	ENV:
*/

void		create_env_lst(t_main *prmtrs, char **env);
void		env_lstsort_bubble(t_env_list *env_head);
t_env_list	*env_lstnew(char **env_arr, int declare_flag);
void		env_lstadd_front(t_env_list **lst, t_env_list *new);
int			env_lstsize(t_env_list *lst);
t_env_list	*env_lstlast(t_env_list *lst);
void		env_lstadd_back(t_env_list **lst, t_env_list *new);
void		env_lstdelone(t_env_list *lst, void *(*del)(char ***arr));
void		env_lstclear(t_env_list **lst, void *(*del)(char ***arr));
void		env_lstiter(t_env_list *lst, void (*f)(void *));
t_env_list	*env_lstmap(t_env_list *lst, void *(*f)(void *),
				void *(*del)(char ***arr));
char		*getvalue_env_lst(char *name, t_env_list *env_head);
void		updatevalue_env_lst(char *name, char *malloced_new_value,
				t_env_list **env_head);
char		**env_split(char const *s);
int			check_env_name_exists(char *name, t_env_list *env_head);
char		**env_create_arr(t_env_list *env_head);
int			my_shell(t_main *prtmtrs);
int			my_shell_execute(t_cmd_list *cmd_i, t_main *prmts);
int			pipe_execve_or_builtins(t_cmd_list *cmd_i, t_main *prmts);
int			redirect_cmd_fd(t_cmd_list *cmd_i);
int			create_pipe(t_cmd_list *cmd_i, t_main *prmts);
int			free_cmd_list(t_main *prmtrs, int return_value);
int			free_prmtrs(t_main *prmtrs, int return_value);
int			cmd_env(char **cmnd_words, t_env_list *env_head,
				int fd_out, t_main *prmtrs);
int			cmd_unset(char **cmnd_words, t_env_list **env_head,
				t_main *prmtrs);
void		unset_delete_lst_element(char *s, t_env_list **env_head);
// cmd
int			cmd_export(char **cmnd_words, t_env_list **env_head,
				int fd_out);
int			print_export_declare_x(t_env_list *env_head, int fd_out);
int			cmd_pwd(int fd_out, t_main *prmtrs);
int			cmd_exit(char **cmnd_words, t_main *prmtrs);
int			cmd_cd(char **cmnd_words, t_env_list *env_head, t_main *prmtrs);
int			cmd_echo(char **cmnd_words, int fd_out);
int			cmd(t_cmd_list *cmd_i, t_main *prmtrs);
int			execute_execve(t_cmd_list *cmd_i, t_main *prmtrs);
void		rl_replace_line(const char *s, int n);

#endif
