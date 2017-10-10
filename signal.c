/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:59:11 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 12:59:12 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_size(int sig)
{
	(void)sig;
	tputs(tgetstr("cl", NULL), 0, put);
	draw_select(g_select.s_argv,
	g_select.status, g_select.cursor);
}

void	sig_int(int sig)
{
	(void)sig;
	tputs(tgetstr("te", NULL), 0, put);
	tputs(tgetstr("ve", NULL), 0, put);
	tcsetattr(0, 0, &g_select.save_term);
	exit(1);
}

void	sig_tstp(int sig)
{
	(void)sig;
	tputs(tgetstr("ve", NULL), 0, put);
	tputs(tgetstr("te", NULL), 0, put);
	tcsetattr(0, TCSANOW, &g_select.save_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void	sig_cont(int sig)
{
	(void)sig;
	signal(SIGTSTP, &sig_tstp);
	dynamic_mode(&g_select.save_term);
	tputs(tgetstr("ti", NULL), 0, put);
	tputs(tgetstr("cl", NULL), 0, put);
	tputs(tgetstr("vi", NULL), 0, put);
	draw_select(g_select.s_argv,
			g_select.status, g_select.cursor);
}

void	sigtest(void)
{
	signal(SIGINT, sig_int);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGQUIT, sig_int);
	signal(SIGWINCH, sig_size);
}
