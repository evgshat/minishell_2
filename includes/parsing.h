/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:21:22 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 22:14:03 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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
int		ch_input(char *line, t_main *prmtrs);
int		ft_isspace(char c);
int		ch_pipe(t_main *prmtrs, char *line);
int		ch_red(char *line);
int		find_red(t_cmd_list *tmp, int i);
int		handle_quotes(t_main *prmtrs);
int		len_of_array(const t_cmd_list *tmp);
int		len_of_str(char *line, int i);
char	*find_dollar(t_cmd_list *tmp, int i, t_main *prmtrs);
int		find_builtin(t_cmd_list *tmp, int i);
int		single_l_red(t_cmd_list *tmp, int i);
int		single_r_red(t_cmd_list *tmp, int i);
int		double_l_red(t_cmd_list *tmp, int i);
int		double_r_red(t_cmd_list *tmp, int i);
int		single_l_fd(t_cmd_list *tmp);
int		single_r_fd(t_cmd_list *tmp);
int		double_l_fd(t_cmd_list *tmp);
int		double_r_fd(t_cmd_list *tmp);
int		creat_cmd_list(t_main *prmtrs);
char	*delete_spaces(char *str);
int		a_red(int j, t_cmd_list *tmp);
int		b_alnum(int *j, t_cmd_list *tmp);
int		b_quote(int *j, t_cmd_list *tmp);
int		b_quotes(int *j, t_cmd_list *tmp);
int		b_red(int *j, t_cmd_list *tmp);
void	a_alnum(int j, t_cmd_list *tmp);
void	a_quote(int j, t_cmd_list *tmp);
void	a_quotes(int j, t_cmd_list *tmp);
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
int		ch_line(char *line);

#endif
