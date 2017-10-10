/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:13:21 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 13:37:48 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		put(int c)
{
	write(0, &c, 1);
	return (0);
}

int		dynamic_mode(struct termios *save_term)
{
	struct termios	term;
	char			buffer[2048];
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Env is empty\n", 2);
		return (-1);
	}
	if (tgetent(buffer, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	*save_term = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 1;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	g_select.s_argv = argv;
	g_select.s_argc = argc;
	if (argc < 2)
	{
		ft_putstr_fd("Too few arguments ...\n", 2);
		return (-1);
	}
	sigtest();
	if (dynamic_mode(&g_select.save_term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 0, put);
	tputs(tgetstr("cl", NULL), 0, put);
	tputs(tgetstr("vi", NULL), 0, put);
	core(argc, argv, &g_select);
	tputs(tgetstr("ve", NULL), 0, put);
	tputs(tgetstr("te", NULL), 0, put);
	if (tcsetattr(0, 0, &g_select.save_term) == -1)
		return (-1);
	return (0);
}
