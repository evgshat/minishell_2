# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 18:43:52 by lcharlet          #+#    #+#              #
#    Updated: 2022/03/16 22:09:14 by lcharlet         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS	=	$(MAIN)				\
			$(LIB)				\
			$(GET_NEXT_LINE)	\
			$(PARSING)		\
			$(MY_SHELL)			\

MAIN_DIR 	= 	srcs/
MAIN		= 	$(MAIN_DIR)main.c

INCLD 	= 	includes/
HDRS	=	$(INCLD)libft.h\
			$(INCLD)get_next_line.h\
			$(INCLD)my_structures.h\
			$(INCLD)parsing.h\
			$(INCLD)my_shell.h\

LIBFT_DIR 	= srcs/libft/
LIBFT 		= $(LIBFT_DIR)libft.a

GET_NEXT_LINE_DIR 	= 	srcs/get_next_line/
GET_NEXT_LINE		= 	$(GET_NEXT_LINE_DIR)get_next_line.c\
						$(GET_NEXT_LINE_DIR)get_next_line_utils.c\

PARSING_DIR		= 	srcs/parsing/
PARSING			=	$(PARSING_DIR)parsing.c\
						$(PARSING_DIR)ch_input.c\
						$(PARSING_DIR)ch_pipe.c\
						$(PARSING_DIR)ch_red.c\
						$(PARSING_DIR)look_quotes.c\
						$(PARSING_DIR)ft_isspace.c\
						$(PARSING_DIR)find_red.c\
						$(PARSING_DIR)handle_quotes.c\
						$(PARSING_DIR)len_of_array.c \
						$(PARSING_DIR)len_of_str.c\
						$(PARSING_DIR)find_dollar.c\
						$(PARSING_DIR)find_builtin.c\
						$(PARSING_DIR)double_r_red.c\
						$(PARSING_DIR)double_l_red.c\
						$(PARSING_DIR)single_l_red.c\
						$(PARSING_DIR)single_r_red.c\
						$(PARSING_DIR)single_r_fd.c \
						$(PARSING_DIR)single_l_fd.c\
						$(PARSING_DIR)double_l_fd.c\
						$(PARSING_DIR)double_r_fd.c\
						$(PARSING_DIR)creat_cmd_list.c\
						$(PARSING_DIR)delete_spaces.c\
						$(PARSING_DIR)b_red.c\
						$(PARSING_DIR)a_red.c\
						$(PARSING_DIR)a_alnum.c\
						$(PARSING_DIR)a_quotes.c\
						$(PARSING_DIR)a_quote.c\
						$(PARSING_DIR)b_alnum.c\
						$(PARSING_DIR)b_quotes.c\
						$(PARSING_DIR)b_quote.c\
						$(PARSING_DIR)make_str.c\
						$(PARSING_DIR)routine.c\
						$(PARSING_DIR)dollar.c\
						$(PARSING_DIR)serch.c\
						$(PARSING_DIR)skip_space.c\
						$(PARSING_DIR)quote.c\
						$(PARSING_DIR)quotes.c\
						$(PARSING_DIR)al_num.c\
						$(PARSING_DIR)setup_terminal.c\
						$(PARSING_DIR)sigint_handler.c\
						$(PARSING_DIR)ch_line.c\

MY_SHELL_DIR		= 	srcs/my_programm/
ENV					=	$(MY_SHELL_DIR)env/
MANAGER				=	$(MY_SHELL_DIR)shell/
CMD_DIR				=	$(MY_SHELL_DIR)cmd/
EXECUTE_EXECVE		=	$(MY_SHELL_DIR)execute_execve/
TESTERS				=	$(MY_SHELL_DIR)4_testers/


MY_SHELL			= 	$(MY_SHELL_DIR)my_shell.c\
						\
						$(ENV)create_env.c\
						$(ENV)env_lstsort_bubble.c\
                        $(ENV)env_lstnew.c\
                        $(ENV)env_lstadd_front.c\
                        $(ENV)env_lstdelone.c\
                        $(ENV)env_lstsize.c \
                        $(ENV)env_lstlast.c \
                        $(ENV)env_lstadd_back.c\
                        $(ENV)env_lstclear.c\
                        $(ENV)env_lstiter.c\
                        $(ENV)env_lstmap.c\
                        $(ENV)getvalue_env_lst.c\
                        $(ENV)updatevalue_env_lst.c\
                        $(ENV)env_split.c\
                        $(ENV)ch_env_name_exists.c\
                        $(ENV)env_create_arr.c\
						\
                        $(MANAGER)my_shell_execute.c\
                        $(MANAGER)pipe_execve_or_builtins.c\
                        $(MANAGER)red_cmd_fd.c\
                        $(MANAGER)create_pipe.c\
                        $(MANAGER)free_utils.c\
                        \
                        $(CMD_DIR)cmd_env.c\
                        $(CMD_DIR)cmd_unset.c\
                        $(CMD_DIR)cmd_export.c\
						$(CMD_DIR)cmd_pwd.c\
						$(CMD_DIR)cmd_echo.c\
						$(CMD_DIR)cmd_cd.c\
						$(CMD_DIR)cmd_exit.c\
						$(CMD_DIR)cmd.c\
                        \
                        $(EXECUTE_EXECVE)execute_execve.c\

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(LIBFT) readline/libhistory.a readline/libreadline.a -ltermcap $(OBJ) -o $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

clean:
			make clean -C $(LIBFT_DIR)
			@rm -rf $(OBJ)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			@rm -rf $(NAME)

re:			fclean all

