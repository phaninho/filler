/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/24 18:41:17 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

char		get_opponent_char(char c)
{
	if (c == 'x')
		return('o');
	return ('x');
}

void		free_piece_and_board(t_env *e)
{
	int		y;

	y = -1;
	while (++y < e->sby)
		free(e->board[y]);
	free(e->board);
	y = -1;
	while (++y < e->spy)
		free(e->piece[y]);
	free(e->piece);
}



void		print_coord(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		call_fctn(t_env *e, char c, int cut_map_horiz)
{
	int		cut_map_diag;

	cut_map_horiz = 0;
	alloc_and_fill(e);
	if (e->play)
	{
		e->play = 0;
		e->px = 0;
		e->py = 0;
		if ((c == 'o' && e->sby != 100) || (e->sby == 100 && c == 'x'))
		{
			cut_map_diag = cut_the_map_for_o(e, c, -2, -2);
			if (cut_map_diag)
				cut_map_horiz = cut_map_horiz_for_o(e, c, -2, -2);
		}
		else
		{
			cut_map_diag = cut_the_map_for_x(e, c, 100, 100);
			if (cut_map_diag)
				cut_map_horiz = cut_map_horiz_for_x(e, c, 100, 100);
		}
		if (cut_map_horiz && cut_map_diag)
			find_c_in_board(e, c);
		print_coord(e->playx, e->playy);
	}
}

int			main()
{
	char	c;
	t_env	e;

	e.px = 0;
	e.py = 0;
	e.play = 0;
	if (get_next_line(0, &(e).buff) > 0)
	{
		c = e.buff[10] == '1' ? 'o' : 'x';
		free(e.buff);
	}
	while (get_next_line(0, &(e).buff) > 0)
	{
		call_fctn(&e, c, 0);
		free(e.buff);
	}
	return (0);
}
