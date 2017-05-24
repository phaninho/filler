/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:18:39 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/24 18:52:57 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_piece(t_env *e)
{
	int		y;
	int		x;
	char	*tmp;

	tmp = NULL;
	y = 0;
	while (y < e->spy && get_next_line(0, &tmp) > 0)
	{
		x = 0;
		while (x < e->spx)
		{
			e->piece[y][x] = tmp[x];
			x++;
		}
		free(tmp);
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

void		alloc_and_fill(t_env *e)
{
	if (e->buff && e->buff[0] && (e->buff[0] == 'P' && e->buff[1] == 'l'))
		board_alloc(e, -1);
	else if (e->buff && e->buff[0] && (e->buff[0] == ' ' || e->buff[0] == '0'))
		fill_board(e);
	else if (e->buff && e->buff[0] && (e->buff[0] == 'P' && e->buff[1] == 'i'))
		add_piece(e);
}
