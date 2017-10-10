/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:15:46 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/25 13:28:08 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		len(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] & 0xC0) != 0x80)
			j++;
		i++;
	}
	return (j);
}

int		get_len_max(char **argv)
{
	int i;
	int len_max_word;

	i = 1;
	len_max_word = 0;
	while (argv[i])
	{
		if (!len_max_word)
			len_max_word = len(argv[i]);
		if (len_max_word < len(argv[i]))
			len_max_word = len(argv[i]);
		i++;
	}
	return (len_max_word);
}

int		parse_line(int ref, char **argv)
{
	int i;
	int object;

	i = 0;
	object = get_len_max(argv) + 1;
	while (ref >= object)
	{
		ref -= object;
		i++;
	}
	return (i);
}

int		check(int size_max)
{
	struct winsize	w;
	int				n;
	int				nb_wpl;

	ioctl(0, TIOCGWINSZ, &w);
	nb_wpl = parse_line(w.ws_col, g_select.s_argv);
	n = (w.ws_col * w.ws_row) / ((size_max + 1) * g_select.s_argc);
	if (!n || size_max > w.ws_col)
	{
		ft_putstr_fd("Windows size is too small\n", 0);
		return (1);
	}
	return (0);
}

int		draw_select(char **argv, int *status, int cursor)
{
	struct winsize	w;
	int				i;
	int				size_max;
	int				arg_per_line;

	i = 1;
	ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("cl", NULL), 0, put);
	size_max = get_len_max(argv) + 1;
	g_select.bol = check(size_max);
	arg_per_line = parse_line(w.ws_col, argv);
	while (argv[i] && g_select.bol == 0)
	{
		g_select.bol = check(size_max);
		while (arg_per_line > 0 && argv[i])
		{
			draw_select_ext(cursor, status, &i, size_max);
			status[i] != 0 ? arg_per_line-- : 0;
			i++;
		}
		arg_per_line = parse_line(w.ws_col, argv);
		ft_putchar_fd('\n', 0);
	}
	return (0);
}
