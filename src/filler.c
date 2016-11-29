/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/29 17:10:48 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		board_alloc(t_env *e, int i)
{
	if (e->buff[9] == '5')
	{
		e->sbx = 17;
		e->sby = 15;
	}
	if (e->buff[9] == '4')
	{
		e->sbx = 40;
		e->sby = 24;
	}
	if (e->buff[9] == '0')
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
	lnb[0] = e->buff[1];
	lnb[1] = e->buff[2];
	lnb[2] = '\0';
	if (e->buff[0] == '0')
	{
		while (e->buff[i])
		{
			e->board[ft_atoi(lnb)][i] = e->buff[i + 4];
			i++;
		}
	}
	free(lnb);
}
#include <stdio.h>
void		play_mf(t_env *e, char c)
{
	int		x;
	int		y;

	y = 0;
	while (e->board[y])
	{
		x = 0;
	//	fprintf(stderr, "entre x:%d y:%d [", x, y);
	//	ft_putchar_fd(e->board[0][16], 2);
	//	ft_putchar_fd(']', 2);
		while (e->board[y][x])
		{
			if (e->board[y][x] == ft_toupper(c))
			{
			fprintf(stderr, "il est la x:%d y:%d [%c]\n", x, y, e->board[y][x]);
				break;
			}
			fprintf(stderr, "x:%d y:%d [%c]\n", x, y, e->board[y][x]);
			x++;
		}
		y++;
	}
}

void		fill_piece(t_env *e)
{
	int		i;
	int		j;
	int		r;

	r = 0;
	i = 0;
	while (get_next_line(0, &(e)->buff) > 0 && i < e->spy)
	{
		j = 0;
		while (j < e->spx)
		{
			e->piece[i][j] = e->buff[j];
			if (!r && e->piece[i][j] == '*')
			{
				e->px = j;
				e->py = i;
				r = 1;
			}
			j++;
		}
		i++;
	}
}

void		add_piece(t_env *e)
{
	char	*addr;
	int		i;

	i = 0;
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



void		call_fctn(t_env *e)
{
	if (e->buff[0] =='P' && e->buff[1] == 'l')
		board_alloc(e, -1);
	else if (e->buff[0] == ' ' || e->buff[0] == '0')
		fill_board(e);
	else if (e->buff[0] == 'P' && e->buff[1] == 'i')
		add_piece(e);
}

int			main()
{
	char	c;
	t_env	e;

	if (get_next_line(0, &(e).buff) > 0)
		c = e.buff[10] == '1' ? 'o' : 'x';
	while (get_next_line(0, &(e).buff) > 0)
		call_fctn(&e);
	play_mf(&e, c);




	int i = 0;
	while (e.board[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("||||---------||||", 2);
		ft_putendl_fd(e.board[i], 2);
		free(e.board[i]);
		i++;
	}
	free(e.board[i]);
	i = 0;
	while (e.piece[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("||||---------||||", 2);
		ft_putendl_fd(e.piece[i], 2);
		free(e.piece[i]);
		i++;
	}
	free(e.piece);
	return (0);
}
