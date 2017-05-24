/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_and_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:25:26 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/24 18:25:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 		test_piece_in_board(t_env *e, int bx, int by, char c)
{
	int		x;
	int		y;
	int		startx;
	int		starty;
	char	oppos_c;

	oppos_c = get_opponent_char(c);
	y = 0;
	bx -= e->px;
	by -= e->py;
	startx = bx;
	starty = by;
	while (y < e->spy)
	{
		x = 0;
		bx = startx;
		while (x < e->spx)
		{
			if (!(x == e->px && y == e->py) && (((bx < 0 || by < 0 || \
			bx >= e->sbx || by >= e->sby) && e->piece[y][x] == '*') || \
			(e->piece[y][x] == '*' && (e->board[by][bx] == c || \
			e->board[by][bx] == ft_toupper(c) || e->board[by][bx] == oppos_c ||\
			e->board[by][bx] == ft_toupper(oppos_c)))))
				return (1);
			bx++;
			x++;
		}
		by++;
		y++;
	}
	e->playx = startx;
	e->playy = starty;
	free_piece_and_board(e);
	return (0);
}

int			place_piece_on_board(t_env *e, int bx, int by, char c)
{
	int		x;
	int		y;
	int 	ret;

	ret = 1;
	y = 0;
	while (ret && y < e->spy)
	{
		x = 0;
		while (ret && x < e->spx)
		{
			if (e->piece && e->piece[y] && e->piece[y][x] && \
			e->piece[y][x] == '*')
			{
				e->px = x;
				e->py = y;
				ret = test_piece_in_board(e, bx, by, c);
			}
			x++;
		}
		y++;
	}
	return (ret);
}

void		find_c_in_board(t_env *e, char c)
{
	int		x;
	int		y;
	int		ret;

	ret = 1;
	y = 0;
	while (ret && y < e->sby)
	{
		x = 0;
		while (ret && x < e->sbx)
		{
			if ((e->board[y][x] == ft_toupper(c) || e->board[y][x] == c))
				ret = place_piece_on_board(e, x, y, c);
			x++;
		}
		y++;
	}
}
