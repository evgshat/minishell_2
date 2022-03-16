/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:35 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 18:27:44 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRUCTURES_H
# define MY_STRUCTURES_H

# include <stdbool.h>
# include <stdio.h>
# define NOT_EXECUTE 1
# define EXECUTE 3
# define ERROR -1
# define SUCCESSFUL_EXIT 0
# define DONT_CLEAN_ENV 100
# define STDIN 0
# define STDOUT 1
# define SRDERR 2

typedef struct s_cmd_list
{
	char				*orig_cmnd_str;
	char				*copy_cmnd_str;
	char				**cmnd_words;
	char				*before_redirect;
	char				*after_redirect;
	bool				is_builtin;
	bool				is_double_r;
	bool				is_double_l;
	bool				is_single_r;
	bool				is_single_l;
	bool				is_pipe;
	int					fd_in;
	int					fd_out;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_env_list
{
	char				**env_arr;
	int					declare_flag;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_main
{
	t_env_list			*env_head;
	t_cmd_list			*cmd_head;
	char				*orig_line_input;
	char				*copy_line_input;
	int					nb_pipes;
	int					fd_output;
	int					exit_status;
}						t_main;

#endif
