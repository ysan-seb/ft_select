/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:17:30 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 13:29:22 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>

typedef struct		s_select
{
	char			buffer[4];
	int				*status;
	int				cursor;
	char			**s_argv;
	int				s_argc;
	int				bol;
	struct termios	save_term;
}					t_select;

t_select			g_select;

int					put(int c);
int					main(int argc, char **argv);
int					get_len_max(char **argv);
int					len(char *str);
int					parse_line(int ref, char **argv);
int					draw_select(char **argv, int *status, int cursor);
void				draw_select_ext(int cursor,
					int *status, int *i, int size_max);
int					*init_status(int argc);
int					print_arg(char *argv, int status, int size_max, int *index);
void				core(int argc, char **argv, t_select *select);
int					ft_test(int *status, int argc);
int					move_left(int *status, int cursor, int argc);
int					move_right(int *status, int cursor, int argc);
void				core_ext(t_select *core, char **argv);
int					dynamic_mode(struct termios *save_term);
void				select_in_out(t_select *core, char **argv);
void				sigtest(void);
void				sig_int(int sig);
void				sig_tstp(int sig);
void				sig_cont(int sig);
void				sig_size(int sig);

#endif
