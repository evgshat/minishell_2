/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:21:22 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:27:19 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRSNG_VLDTN_H
# define PRSNG_VLDTN_H

# include "libft.h"
# include "my_structures.h"
# include "my_shell.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>

# define BREAK -5
# define CONTINUE -7

void	rl_replace_line(const char *s, int n);
int		parsing(t_main *prmtrs);
int		check_input(char *line, t_main *prmtrs);
int		ft_isspace(char c);
int		check_pipe(t_main *prmtrs, char *line);
int		check_redirect(char *line);
int		find_redirect(t_cmd_list *tmp, int i);
int		handle_quotes(t_main *prmtrs);
int		len_of_array(const t_cmd_list *tmp);
int		len_of_str(char *line, int i);
char	*find_dollar(t_cmd_list *tmp, int i, t_main *prmtrs);
int		find_builtin(t_cmd_list *tmp, int i);
int		single_l_redirect(t_cmd_list *tmp, int i);
int		single_r_redirect(t_cmd_list *tmp, int i);
int		double_l_redirect(t_cmd_list *tmp, int i);
int		double_r_redirect(t_cmd_list *tmp, int i);
int		single_l_fd(t_cmd_list *tmp);
int		single_r_fd(t_cmd_list *tmp);
int		double_l_fd(t_cmd_list *tmp);
int		double_r_fd(t_cmd_list *tmp);
int		creat_cmd_list(t_main *prmtrs);
char	*delete_spaces(char *str);
int		after_redirect(int j, t_cmd_list *tmp);
int		be_alnum(int *j, t_cmd_list *tmp);
int		be_quote(int *j, t_cmd_list *tmp);
int		be_quotes(int *j, t_cmd_list *tmp);
int		before_redirect(int *j, t_cmd_list *tmp);
void	af_alnum(int j, t_cmd_list *tmp);
void	af_quote(int j, t_cmd_list *tmp);
void	af_quotes(int j, t_cmd_list *tmp);
int		al_num(t_cmd_list **tmp, int i, int ind);
int		quotes(t_cmd_list **tmp, int i, int ind, t_main *prmtrs);
int		quote(t_cmd_list **tmp, int i, int ind);
int		skip_space(t_cmd_list **tmp, int i);
int		serch(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs);
int		dollar(t_cmd_list **tmp, int i, int ind, t_main *prmtrs);
int		routine(t_cmd_list **tmp, int *i, int ind, t_main *prmtrs);
int		make_str(char *line, int i, t_cmd_list **tmp, int *ind);
int		setup_terminal(void);
void	sigint_handler(int signum);
int		look_quotes(char *line);
int		check_line(char *line);

#endif
