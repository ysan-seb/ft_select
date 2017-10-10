/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:16:55 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 13:18:38 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	core(int argc, char **argv, t_select *select)
{
	select->status = init_status(argc);
	select->cursor = 1;
	while (!(select->buffer[0] == 27 && select->buffer[2] == 0))
	{
		core_ext(select, argv);
		if (ft_test(select->status, argc) == 0)
		{
			tputs(tgetstr("cl", NULL), 0, put);
			break ;
		}
		if (select->buffer[0] == 27 && select->buffer[2] == 68)
			select->cursor = move_left(select->status, select->cursor, argc);
		if (select->buffer[0] == 27 && select->buffer[2] == 67)
			select->cursor = move_right(select->status, select->cursor, argc);
		tputs(tgetstr("cl", NULL), 0, put);
		draw_select(argv, select->status, select->cursor);
		ft_memset(select->buffer, 0, 4);
		read(0, &select->buffer, 4);
	}
}

void	select_in_out(t_select *core, char **argv)
{
	int i;

	i = 1;
	while (i < core->s_argc)
	{
		if (core->status[i] == 3)
		{
			ft_putstr_fd(argv[i], 1);
			ft_putchar_fd(' ', 1);
		}
		i++;
	}
}

int		move_left(int *status, int cursor, int argc)
{
	if (cursor == 1)
		cursor = argc - 1;
	else
		cursor--;
	while (status[cursor] == 0)
	{
		if (cursor == 1)
			cursor = argc - 1;
		else
			cursor--;
	}
	return (cursor);
}

int		move_right(int *status, int cursor, int argc)
{
	if (cursor == argc - 1)
		cursor = 1;
	else
		cursor++;
	while (status[cursor] == 0)
	{
		if (cursor == argc - 1)
			cursor = 1;
		else
			cursor++;
	}
	return (cursor);
}

int		ft_test(int *status, int argc)
{
	int i;

	i = 1;
	while (i <= argc)
	{
		if (status[i] != 0)
			return (1);
		i++;
	}
	return (0);
}
