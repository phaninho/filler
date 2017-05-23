/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/23 16:04:04 by stmartin         ###   ########.fr       */
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
			if (by == e->sby - 1)
				by = -1;
			if (!(x == e->px && y == e->py) && (((bx < 0 || by < 0 || bx >= e->sbx /*|| by >= e->sby*/) && e->piece[y][x] == '*') \
			|| (e->piece[y][x] == '*' && (e->board[by][bx] == c || e->board[by][bx] == ft_toupper(c) || e->board[by][bx] == oppos_c || e->board[by][bx] == ft_toupper(oppos_c)))))
				return (1);
			bx++;
			x++;
		}
		by++;
		y++;
	}
	e->playx = startx;
	e->playy = starty;
	// ft_putnbr(starty);
	// ft_putchar(' ');
	// ft_putnbr(startx);
	// ft_putchar('\n');
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

int			cut_map_horiz_for_x(t_env *e, char c)
{
	int		x;
	int		y;
	int		ret;
	int		xmax;
	int		ymax;

	xmax = 100;
	ymax = 100;
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

int			cut_the_map_for_x(t_env *e, char c)
{
	int		x;
	int		y;
	int		ret;
	int		xmax;
	int		ymax;

	xmax = 100;
	ymax = 100;
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

int			cut_map_horiz_for_o(t_env *e, char c)
{
	int		x;
	int		y;
	int		ret;
	int		xmax;
	int		ymax;

	xmax =0;
	ymax = 0;
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

int			cut_the_map_for_o(t_env *e, char c)
{
	int		x;
	int		y;
	int		ret;
	int		xmax;
	int		ymax;

	xmax = -2;
	ymax = -2;
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

void			image_put_pixel(t_env *e, int x, int y, unsigned long color)
{
	int		pos;
	int		size;

	size = ((y * 10 - 1) * e->img.szline) + (x * 10 * e->img.bpp / 8);
	pos = (y * e->img.szline) + (x * e->img.bpp / 8);
	if (pos > 0 && pos + 2 < size && x >= 0
		&& (x * e->img.bpp / 8) < e->img.szline)
	{
		e->img.data[pos + 2] = color / 65536 % 256;
		e->img.data[pos + 1] = color / 256 % 256;
		e->img.data[pos] = color % 256;
	}
}

void		print_board(t_env *e, int x, int y)
{
	int		dx;
	int		dy;
	int		dex;
	int		dey;

	dy = -1 + y * 10;
	dex = x + 10;
	dey = x + 10;
	while (++dy < dey)
	{
		dx = -1 + x * 10;
		while (++dx < dex)
		{
			if (e->board[y][x] == '.')
				image_put_pixel(e, dx, dy, 0x918787);
			else if (e->board[y][x] == 'X' || e->board[y][x] == 'x')
				image_put_pixel(e, dx, dy, 0x212D9A);
			else if (e->board[y][x] == 'O' || e->board[y][x] == 'o')
				image_put_pixel(e, dx, dy, 0xAB2020);
		}
	}
}

void 		draw_window(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->sby)
	{
		x = -1;
		while (++x < e->sbx)
			print_board(e, x, y);
	}
}

	void	place_piece(t_env *e, char c)
{
	int		cut_map_diag;
	int		cut_map_horiz;

	cut_map_horiz = 0;
	cut_map_diag = 0;
	if (e->play)
	{
		e->playx = -100;
		e->playy = -100;
		e->play = 0;
		e->px = 0;
		e->py = 0;
		if ((c == 'o' && e->sby != 100) || (e->sby == 100 && c == 'x'))
		{
			cut_map_diag = cut_the_map_for_o(e, c);
			if (cut_map_diag)
				cut_map_horiz = cut_map_horiz_for_o(e, c);
		}
		else
		{
			cut_map_diag = cut_the_map_for_x(e, c);
			if (cut_map_diag)
				cut_map_horiz = cut_map_horiz_for_x(e, c);
		}
		if (cut_map_horiz && cut_map_diag)
			find_c_in_board(e, c);
		if (e->playy == -100 && e->playx == -100)
		{
			ft_putstr("0 0\n");
		//	mlx_destroy_image(e->mlx, e->img.i);
		//	mlx_destroy_window(e->mlx, e->win);
			exit (1);
		}
		ft_putnbr(e->playy);
		ft_putchar(' ');
		ft_putnbr(e->playx);
		ft_putchar('\n');
	}
}

static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while (y <= e->img.szline * 1000)
	{
		e->img.data[y] = 0;
		y++;
	}
}

int			destroy_win(t_env *e)
{
	(void)e;
	exit(1);
	return (0);
}

int 		expose_hook(t_env *e)
{
	clear_image(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (0);
}
int		key_hook(int kc, t_env *e)
{
if (kc == 53)
	exit(1);
expose_hook(e);
return (0);
}

void		lets_print(t_env *e)
{
	draw_window(e);
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Filler Arena");
	e->img.i = mlx_new_image(e->mlx, 1000, 1000);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, DESTROYNOTIFY, STRUCT_NOT_MASK, destroy_win, &e);
	mlx_hook(e->win, 2, 1L << 0, key_hook, e);
	e->img.data = mlx_get_data_addr(e->img.i, &(e->img.bpp), &(e->img.szline),
			&(e->img.endian));
	mlx_loop(e->mlx);
}

	int		call_fctn(t_env *e)
{
	if (get_next_line(0, &(e)->buff) > 0)
	{
		if (e->buff && e->buff[0] && (e->buff[0] =='P' && e->buff[1] == 'l'))
			board_alloc(e, -1);
		else if (e->buff && e->buff[0] && (e->buff[0] == ' ' || e->buff[0] == '0'))
			fill_board(e);
		else if (e->buff && e->buff[0] && (e->buff[0] == 'P' && e->buff[1] == 'i'))
			add_piece(e);
		if (e->play)
			place_piece(e, e->c);
		free(e->buff);
	}
	return (1);
}

int			main()
{
	t_env	e;

	e.px = 0;
	e.py = 0;
	e.play = 0;
	e.out = 1;
	if (!(e.mlx = mlx_init()))
	{
		ft_putstr("mlx_init error!\n");
		return (1);
	}
	if (get_next_line(0, &(e).buff) > 0)
	{
		e.c = e.buff[10] == '1' ? 'o' : 'x';
		free(e.buff);
	}
	//while (get_next_line(0, &(e).buff) > 0)
		//call_fctn(&e);
		mlx_loop_hook(e.mlx, call_fctn, &e);
		mlx_loop(e.mlx);
	/*lets_print(&e);
	expose_hook(&e);*/
	return (0);
}
