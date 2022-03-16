/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:38:33 by lcharlet          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:47 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	setup_terminal(void)
{
	struct termios	term;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_handler);
	if (tcgetattr(0, &term) != 0)
		return (1);
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return (1);
	return (0);
}
