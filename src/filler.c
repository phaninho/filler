/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2017/01/17 17:25:06 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int 		test_piece_on_board(t_env *e, int bx, int by, char c)
{
	int		x;
	int		y;
	int		startx;
	int		starty;
	char	oppos_c;

	if (c == 'x')
		oppos_c = 'o';
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
			// if (x == e->px && y == e->py)
			// {
			// 	//if (by >= 0 && by < e->sby && bx >= 0 & bx < e->sbx && e->board && e->piece && e->board[by] && e->board[by][bx] && e->piece[y] && e->piece[y][x])
			// 		//dprintf(2, "++++++++board[%d:%d][%c] piece[%d:%d][%c]\n", bx, by,e->board[by][bx], x, y, e->piece[y][x]);
			// 	if (x < e->spx - 1)
			// 	{
			// 		bx++;
			// 		x++;
			// 	}
			// 	else
			// 		break;
			// }
		//	if (by >= 0 && by < e->sby && bx >= 0 & bx < e->sbx && e->board && e->piece && e->board[by] && e->board[by][bx] && e->piece[y] && e->piece[y][x])
			//	dprintf(2, "|||||||||board[%d:%d][%c] piece[%d:%d][%c]\n", bx, by,e->board[by][bx], x, y, e->piece[y][x]);
			if (!(x == e->px && y == e->py) && (((bx < 0 || by < 0 || bx >= e->sbx || by >= e->sby) && e->piece[y][x] == '*') \
			|| (e->piece[y][x] == '*' && (e->board[by][bx] == c || e->board[by][bx] == ft_toupper(c) || e->board[by][bx] == oppos_c || e->board[by][bx] == ft_toupper(oppos_c)))))
			{
			//	dprintf(2, "MP\n");
				return (1);
			}
			bx++;
			x++;
		}
		by++;
		y++;
	}
	e->playx = startx;
	e->playy = starty;
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
			if (e->piece && e->piece[y] && e->piece[y][x] && e->piece[y][x] == '*')
			{
				e->px = x;
				e->py = y;
				//dprintf(2, "test_piece\n");
				ret = test_piece_on_board(e, bx, by, c);
				//fprintf(stderr, "////////////by:%d bx:%d////////////\n", by, bx);
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

void		fill_piece(t_env *e)
{
	int		y;
	int		x;

	y = 0;
	while (y < e->spy  && get_next_line(0, &(e)->buff) > 0)
	{
		x = 0;
		while (x < e->spx)
		{
			e->piece[y][x] = e->buff[x];
			x++;
		}
		y++;
	}
}

void		add_piece(t_env *e)
{
	char	*addr;
	int		i;

	i = 0;
	e->play = 1;
	addr = ft_strchr(e->buff, ' ');
	e->spy = ft_atoi(addr++);
	addr = ft_strchr(addr, ' ');
	e->spx = ft_atoi(addr++);
	e->piece = (char **)malloc(sizeof(char *) * (e->spy + 1));
	e->piece[e->spy] = NULL;
	while (i < e->spy)
	{
		e->piece[i] = (char *)malloc(sizeof(char) * (e->spx + 1));
		e->piece[i][e->spx] = '\0';
		i++;
	}
	fill_piece(e);
}

void		board_alloc(t_env *e, int i)
{
	if (e->buff[9] && e->buff[9] == '5')
	{
		e->sbx = 17;
		e->sby = 15;
	}
	else if (e->buff[9] && e->buff[9] == '4')
	{
		e->sbx = 40;
		e->sby = 24;
	}
	else if (e->buff[9] && e->buff[9] == '0')
	{
		e->sbx = 99;
		e->sby = 100;
	}
	e->board = (char **)malloc(sizeof(char *) * (e->sby + 1));
	e->board[e->sby] = NULL;
	while (++i < e->sby)
	{
		e->board[i] = (char *)malloc(sizeof(char) * (e->sbx + 1));
		e->board[i][e->sbx] = '\0';
	}
}

void		fill_board(t_env *e)
{
	char	*lnb;
	int		i;

	i = 0;
	lnb = (char *)malloc(sizeof(char) * 3);
	if (lnb && e->buff)
	{
		lnb[0] = e->buff[1];
		lnb[1] = e->buff[2];
		lnb[2] = '\0';
	}
	if (e->buff[0] == '0')
	{
		while (e->buff && e->buff[i])
		{
			e->board[ft_atoi(lnb)][i] = e->buff[i + 4];
			i++;
		}
	}
	free(lnb);
}

void		call_fctn(t_env *e, char c)
{
	if (e->buff && e->buff[0] && (e->buff[0] =='P' && e->buff[1] == 'l'))
		board_alloc(e, -1);
	else if (e->buff && e->buff[0] && (e->buff[0] == ' ' || e->buff[0] == '0'))
		fill_board(e);
	else if (e->buff && e->buff[0] && (e->buff[0] == 'P' && e->buff[1] == 'i'))
		add_piece(e);
	if (e->play)
	{
		e->play = 0;
		e->px = 0;
		e->py = 0;
		e->out++;
		//dprintf(2, "new playyyyyyyyyyyyyyy [tour: %d sym: %c]\n", e->out, c);
		find_c_in_board(e, c);
		//dprintf(2, "coordonnee trouvee y:%d x:%d\n", e->playy, e->playx);
		ft_putnbr(e->playy);
		ft_putchar(' ');
		ft_putnbr(e->playx);
		ft_putchar('\n');
	}
}

int			main()
{
	char	c;
	t_env	e;

	e.px = 0;
	e.py = 0;
	e.play = 0;
	e.out = 0;
	if (get_next_line(0, &(e).buff) > 0)
		c = e.buff[10] == '1' ? 'o' : 'x';
	while (get_next_line(0, &(e).buff) > 0)
		call_fctn(&e, c);
	return (0);
}
