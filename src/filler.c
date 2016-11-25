/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:57 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/25 16:37:01 by stmartin         ###   ########.fr       */
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
#include <stdio.h>
void		call_fctn(t_env *e, char c)
{
	if (e->buff[0] =='P' && e->buff[1] == 'l')
		board_alloc(e);
	else if (e->buff[0] == ' ' || e->buff[0] == '0')
		fill_board(e);


	 fprintf(stderr , "----[%s]------\n", e->buff);
	(void)c;
}

int			main()
{
	char	c;
	t_env	e;

	if (get_next_line(0, &(e).buff) > 0)
		c = e.buff[10] == '1' ? 'o' : 'x';
	while (get_next_line(0, &(e).buff) > 0)
		call_fctn(&e, c);
	int i = 0;
	while (e.board && (i < 15))
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("||||---------||||", 2);
		ft_putendl_fd(e.board[i], 2);
		i++;
	}return (0);
}
