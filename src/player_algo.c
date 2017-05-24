/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:21:38 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/24 18:22:02 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			cut_map_horiz_for_x(t_env *e, char c, int xmax, int ymax)
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
			{
					if (x < xmax)
					{
						xmax = x;
						ymax = y;
					}
			}
			x++;
		}
		y++;
	}
	return (place_piece_on_board(e, xmax, ymax, c));
}

int			cut_the_map_for_x(t_env *e, char c, int xmax, int ymax)
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
			{
					if (x < xmax || y < ymax)
					{
						xmax = x;
						ymax = y;
					}
			}
			x++;
		}
		y++;
	}
	return (place_piece_on_board(e, xmax, ymax, c));
}

int			cut_map_horiz_for_o(t_env *e, char c, int xmax, int ymax)
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
			{
					if (x > xmax)
					{
						xmax = x;
						ymax = y;
					}
			}
			x++;
		}
		y++;
	}
	return (place_piece_on_board(e, xmax, ymax, c));
}

int			cut_the_map_for_o(t_env *e, char c, int xmax, int ymax)
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
			{
					if (x > xmax || y > ymax)
					{
						xmax = x;
						ymax = y;
					}
			}
			x++;
		}
		y++;
	}
	return (place_piece_on_board(e, xmax, ymax, c));
}
