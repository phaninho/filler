/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/25 17:43:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		board_alloc(t_env *e)
{
	int		x;
	int		y;
	int		i;

	i = -1;
	if (e->buff[9] == '5')
	{
		x = 17;
		y = 15;
	}
	if (e->buff[9] == '4')
	{
		x = 40;
		y = 24;
	}
	if (e->buff[9] == '0')
	{
		x = 99;
		y = 100;
	}
	e->board = (char **)malloc(sizeof(char *) * (y + 1));
	e->board[y] = NULL;
	while (++i < y)
	{
		e->board[i] = (char *)malloc(sizeof(char ) * (x + 1));
		e->board[i][x] = '\0';
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

void		fill_piece(t_env *e, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (get_next_line(0, &(e)->buff) > 0 && i < y)
	{
		j = 0;
		while (j < x)
		{
			e->piece[i][j] = e->buff[j];
			j++;
		}
		i++;
	}
}

void		add_piece(t_env *e)
{
	char	*addr;
	int		x;
	int		y;
	int		i;

	i = 0;
	addr = ft_strchr(e->buff, ' ');
	y = ft_atoi(addr++);
	addr = ft_strchr(addr, ' ');
	x = ft_atoi(addr++);
	e->piece = (char **)malloc(sizeof(char *) * (y + 1));
	e->piece[y] = NULL;
	while (i < y)
	{
		e->piece[i] = (char *)malloc(sizeof(char) * (x + 1));
		e->piece[i][x] = '\0';
		i++;
	}
	fill_piece(e, x, y);
}


#include <stdio.h>
void		call_fctn(t_env *e, char c)
{
	if (e->buff[0] =='P' && e->buff[1] == 'l')
		board_alloc(e);
	else if (e->buff[0] == ' ' || e->buff[0] == '0')
		fill_board(e);
	else if (e->buff[0] == 'P' && e->buff[1] == 'i')
		add_piece(e);
//	else
//		play_mf(e, c);

	(void)c;
}

int			main()
{
	char	c;
	t_env	e;

	if (get_next_line(0, &(e).buff) > 0)
		c = e.buff[10] == '1' ? 'o' : 'x';
	while (get_next_line(0, &(e).buff) > 0)
	 fprintf(stderr , "----[%s]------\n", e->buff);
		call_fctn(&e, c);




	int i = 0;
	while (e.board[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("||||---------||||", 2);
		ft_putendl_fd(e.board[i], 2);
		i++;
	}
	i = 0;
	while (e.piece[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("||||---------||||", 2);
		ft_putendl_fd(e.piece[i], 2);
		i++;
	}
	return (0);
}
