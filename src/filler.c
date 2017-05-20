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
/*
int			test_piece(t_env *e, int bx, int by)
{
	int		x;
	int		y;
(void)bx;
(void)by;

	y = e->py;
	x = e->px;
	while (y < e->spy)
	{
		while (x < e->spx)
		{
			if (e->piece[y][x] == '*')
			 {
				 e->px = x;
				 e->py = y;
				 return (1);
			 }
			x++;
		}
		x = 0;
		y++;
	}
	return (-1);
}

int			compare_board_and_piece(t_env *e, int bx, int by, char c)
{//ft_putstr_fd("demarage de compare b and p\n", 2);
	int		x;
	int		y;
	int		ret;
	int		starin;

	starin = 0;
	x = e->px;
	y = e->py;
	ret = e->spx * e->spy - 1; // pour parcourir tous les elements de la piece
	//ft_putstr_fd("ret au debut [", 2);
	//ft_putnbr_fd(ret, 2);
		//	ft_putendl_fd("]", 2);

		//if (bx + (e->spx - x) < 0 || by + (e->spy - y) < 0 || bx + (e->spx - x) > e->sbx || by + (e->spy - y) > e->sby)
	//{
	//	fprintf(stderr, "laaaaaaaaa spx:%d spy:%d   %d    %d  x:%d  y:%d bx:%d by:%d\n",e->spx, e->spy,  bx + (e->spx - x  + 1), by + (e->spy - y  + 1), x, y, bx, by);
	//	return (ret);
	//}
	while (y < e->spy)
	{
		while (x < e->spx)
		{
			if (e->piece[y][x] == '.')
				ret--;
			else if (e->piece[y][x] == '*' && e->board[y + by][x + bx] == '.')
				ret--;
			else if (e->piece[y][x] == '*' && (e->board[y + by][x + bx] == c || e->board[y + by][x + bx] == ft_toupper(c)) && !starin)
			{
				starin++;
				ret--;
			}
			else if (x != e->px && y != e->py && e->board[by + y][bx + x] != '.' && e->piece[y][x] == '*')
				return (ret);
			x++;
			//ft_putstr_fd("ret dans while x[", 2);
		//	ft_putnbr_fd(ret, 2);
				//	ft_putendl_fd("]", 2);
	//			fprintf(stderr, "laaaaaaaaa bx:%d by:%d\n", bx + x, by + y);
					if (!ret)
					{
						e->playx = bx - e->px;
						e->playy = by - e->py;
						ft_putnbr(e->playy);
						ft_putchar(' ');
						ft_putnbr(e->playx);
						ft_putchar('\n');
						e->play = 0;
						return (0);
					}
		}//ft_putstr_fd("ret dans while y[", 2);
	//	ft_putnbr_fd(ret, 2);
				//ft_putendl_fd("]", 2);
		x = 0;
		y++;

	}
	//ft_putstr_fd("sortiiiiiiiiii\n", 2);
	return (1);
}

int 	find_piece_star(t_env *e, int star)
{
	int		x;
	int		y;

	x = e->px + star;
	y = e->py;
	e->out = 0;//fprintf(stderr,"la %d %d\n",e->spx,  e->spy);
	while (!e->out && y < e->spy)
	{
		while (!e->out && x < e->spx)
		{
		//	fprintf(stderr,"%c", e->piece[y][x]);
			if (e->piece[y][x] == '*')
			{
				e->px = x;
				e->py = y;
				e->out++;
				return (1);
			}
			x++;
		}
		//fprintf(stderr,"laaa\n");
		x = 0;
		y++;
	}
	return (-1);
}
*/

int 		test_piece_on_board(t_env *e, int bx, int by)
{
	int		x;
	int		y;
	int		startx;
	int		starty;

	dprintf(2, "test de la piece dans le tableau ==>\n");
	y = 0;
	bx -= e->px;
	by -= e->py;
	startx = bx;
	starty = by;
	//dprintf(2, "starty [%d] startx [%d] by=[%d] bx=[%d]\n", starty, startx, by, bx);
	while (y < e->spy)
	{
		x = 0;
		while (x < e->spx)
		{
			if (x == e->px && y == e->py)
			{
				if (x < e->spx - 1)
					x++;
				else if (x == e->spx - 1 && y < e->spy - 1)
				{
					x = 0;
					y++;
				}
			}
			bx += x;
			by += y;
			if (/*((bx < 0 || by < 0 || bx >= e->sbx || by >= e->sby) && e->piece[y][x] == '*') || \
			(bx >= 0 && by >= 0 && bx < e->sbx && by < e->sby && */ ((bx < 0 || by < 0 || bx >= e->sbx || by >= e->sby) && e->piece[y][x] == '*') || (e->piece[y][x] == '*' && e->board[by][bx] != '.'))
			{
				dprintf(2, "XXXXXXXXX elimineeeeeeeeee\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	e->playx = startx;
	e->playy = starty;
	dprintf(2,"!!!!!!!!!!coord QUALIFIEEEEEE!!!!!!!!!!\n");
	// ft_putnbr(starty);
	// ft_putchar(' ');
	// ft_putnbr(startx);
	// ft_putchar('\n');
	// dprintf(2, "apres affichage de la coord\n");
	return (0);
}

int			place_piece_on_board(t_env *e, int bx, int by)
{
	int		x;
	int		y;
	int 	ret;
//fprintf(stderr, "ssssspy%d\n", e->spy);
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
				dprintf(2, "py[%d] px[%d] by[%d] bx[%d]\n", e->py, e->px, by, bx);
				ret = test_piece_on_board(e, bx, by);
				//fprintf(stderr, "////////////by:%d bx:%d////////////\n", by, bx);
			}
			x++;
		}
		y++;
	}
	return (ret);
}

void		play_mf(t_env *e, char c)
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
				dprintf(2, "*****nouvelle *  trouvee dans le tableau*****\n");
				ret = place_piece_on_board(e, x, y);
			}
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
		dprintf(2, "new playyyyyyyyyyyyyyy [tour: %d sym: %c]\n", e->out, c);
		play_mf(e, c);
		dprintf(2, "coordonnee trouvee y:%d x:%d\n", e->playy, e->playx);
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
