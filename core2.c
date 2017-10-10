/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:19:16 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 13:29:08 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		*init_status(int argc)
{
	int i;
	int *status;

	i = 0;
	status = (int *)malloc(sizeof(int) * (argc) + 1);
	while (i < argc)
	{
		if (i == 0)
		{
			status[i] = 0;
			i++;
		}
		status[i] = 1;
		i++;
	}
	status[i] = 0;
	return (status);
}

int		print_arg(char *argv, int status, int size_max, int *index)
{
	int space;

	space = size_max - len(argv);
	if (status == 0)
		return (*index);
	else if (status == 2)
		ft_putstr_fd(tgetstr("us", NULL), 0);
	else if (status == 3)
		ft_putstr_fd(tgetstr("mr", NULL), 0);
	else if (status == 4)
	{
		ft_putstr_fd(tgetstr("us", NULL), 0);
		ft_putstr_fd(tgetstr("mr", NULL), 0);
	}
	ft_putstr_fd(argv, 0);
	ft_putstr_fd(tgetstr("me", NULL), 0);
	while (space > 0)
	{
		ft_putchar_fd(' ', 0);
		space--;
	}
	return (*index);
}

void	core_ext(t_select *core, char **argv)
{
	if (core->buffer[0] == 10)
	{
		tputs(tgetstr("ve", NULL), 0, put);
		tputs(tgetstr("te", NULL), 0, put);
		select_in_out(core, argv);
		if (tcsetattr(0, 0, &core->save_term) == -1)
			exit(-1);
		exit(0);
	}
	if ((core->buffer[0] == 27 && core->buffer[2] == 51)
			|| core->buffer[0] == 127)
	{
		core->status[core->cursor] = 0;
		core->buffer[0] = 27;
		core->buffer[2] = 67;
	}
	if (core->buffer[0] == 32)
	{
		core->status[core->cursor] = (core->status[core->cursor] != 0
				&& core->status[core->cursor] != 3) ? 3 : 1;
		core->buffer[0] = 27;
		core->buffer[2] = 67;
	}
}

void	draw_select_ext(int cursor, int *status, int *i, int size_max)
{
	if (cursor == *i && status[*i] != 0 && status[*i] != 3)
		print_arg(g_select.s_argv[*i], 2, size_max, i);
	else if (cursor == *i && status[*i] != 0 && status[*i] == 3)
		print_arg(g_select.s_argv[*i], 4, size_max, i);
	else
		print_arg(g_select.s_argv[*i], status[*i], size_max, i);
}
