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
void		board_alloc(t_env *e, int i)
{//fprintf(stderr, "1laaaaaaaaaaaaaaaaaaaaaa\n" );
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
	}//ft_putstr_fd("demarage de boardaloc\n", 2);
}

void		fill_board(t_env *e)
{//fprintf(stderr, "2laaaaaaaaaaaaaaaaaaaaaa\n" );
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
	}//ft_putstr_fd("demarage de fill_board\n", 2);
	free(lnb);
}


int			test_piece(t_env *e, int bx, int by)
{
	int		x;
	int		y;

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

	x = e->px;
	y = e->py;
	ret = e->spx * e->spy; // pour parcourir tous les elements de la piece
	//ft_putstr_fd("ret au debut [", 2);
	//ft_putnbr_fd(ret, 2);
		//	ft_putendl_fd("]", 2);

		//if (bx + (e->spx - x) < 0 || by + (e->spy - y) < 0 || bx + (e->spx - x) > e->sbx || by + (e->spy - y) > e->sby)
	//{
	//	fprintf(stderr, "laaaaaaaaa spx:%d spy:%d   %d    %d  x:%d  y:%d bx:%d by:%d\n",e->spx, e->spy,  bx + (e->spx - x  + 1), by + (e->spy - y  + 1), x, y, bx, by);
	//	return (ret);
	//}

	if (e->board[by][bx] == ft_toupper(c) || e->board[by][bx] == c)
	{

		//bx = bx - e->px;
		//by = by - e->py;
		//x = 0;
		//y = 0;
	//	ft_putstr_fd("ret au premier dec [", 2);
	//	ft_putnbr_fd(ret, 2);
				//ft_putendl_fd("]", 2);
	}
	while (y < e->spy)
	{
		while (x < e->spx)
		{
			if (e->piece[y][x] == '.')
				ret--;
			else if (e->piece[y][x] == '*' && e->board[y + by][x + bx] == '.')
				ret--;
			else if (x != e->px && y != e->py && e->board[by + y][bx + x] != '.' && e->piece[y][x] == '*')
				return (ret);
				//compare_board_and_piece(e, bx + x, by + y, c);
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
	return (-1)
}

void		play_mf(t_env *e, char c)
{
	//ligne a suivre : trouver le bon signe sur le tableau ensuite tester toutes les possiblites d'une piece en modifiant la coordonnee
	//de l'etoile a placer sur le signe du tableau. Si toutes les possibilites sont teste, incrementer la coordonnee sur le tableau jusqu'a
	//trouver a nouveau un signe, de la tester toutes les possibilites de la piece....

	//ft_putstr_fd("demarage de playmf\n", 2);
	int		x;
	int		y;
	int		ret;
	int		star;
	//int		find_star;

	//find_star = 0;
	e->px = 0;
	e->py = 0;
	ret = -1;
	y = 0;
	star = 0;
	//find_piece_star(e, star);
	while (ret && e->board[y])
	{
		x = 0;
		while (ret && e->board[y][x])
		{
			if (ret && (e->board[y][x] == ft_toupper(c) || e->board[y][x] == c))
			{
				if (find_piece_star(e, star) == 1)
				{
					star++;
					ret = compare_board_and_piece(e, x, y, c);
					//mofoier compsre board pour qu'il affiche les bonnes coor ou bien retourne -1 au cas ou il faut tester
					//de modifier les coordonnee de l'etoile dans la piece
				}
				else if (find_piece_star(e, star) == -1)
				{
					star = 0;
					e->px = 0;
					e->py = 0;
				}
				//ft_putstr_fd("ret dans playmf[", 2);
				//ft_putnbr_fd(ret, 2);
				//		ft_putendl_fd("]", 2);
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
	//int		r;
	//int		maxx;
	//int		maxy;

	//maxx = 0;
	//maxy = 0;
	//r = 0;
	y = 0;
	while (y < e->spy  && get_next_line(0, &(e)->buff) > 0)
	{
		x = 0;
		while (x < e->spx)
		{
			e->piece[y][x] = e->buff[x];
			/*if (e->piece[y][x] == '*' && x + 1 >= maxx && y + 1 >= maxy)
			{
				maxx = x + 1;
				maxy = y + 1;
			}
			if (!r && e->piece[y][x] == '*')
			{
				e->px = x;
				e->py = y;
				r = 1;
			}*/
			x++;
		}
		y++;
	}
	//e->spx = maxx;
	//e->spy = maxy;
	//fprintf(stderr, "//////////////////////////spx: %d spx: %d\n", e->spx, e->spy);
	//ft_putstr_fd("sort de fill piece\n", 2);
	//e->out = 1;
}

void		add_piece(t_env *e)
{//ft_putstr_fd("demarage de addpiece\n", 2);
	char	*addr;
	int		i;
//fprintf(stderr, "3laaaaaaaaaaaaaaaaaaaaaa\n" );
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
	//fprintf(stderr,"lalllllll %d %d\n",e->spx,  e->spy);
	fill_piece(e);
}



void		call_fctn(t_env *e, char c)
{//ft_putstr_fd("demarage de callfctn\n", 2);
//fprintf(stderr , "----[%s]------\n", e->buff);
	if (e->buff[0] =='P' && e->buff[1] == 'l')
		board_alloc(e, -1);
	else if (e->buff[0] == ' ' || e->buff[0] == '0')
		fill_board(e);
	else if (e->buff[0] == 'P' && e->buff[1] == 'i')
		add_piece(e);
	//else
	//{
		//fprintf(stderr, "4laaaaaaaaaaaaaaaaaaaaaa\n" );
	if (e->play)
		play_mf(e, c);

	//}
}

int			main()
{
	char	c;
	t_env	e;

	e.px = 0;
	e.py = 0;
	e.play = 0;
	e.out = 0;//ft_putstr_fd("demarage du prog\n", 2);
	if (get_next_line(0, &(e).buff) > 0)
		c = e.buff[10] == '1' ? 'o' : 'x';
	while (get_next_line(0, &(e).buff) > 0)
		call_fctn(&e, c);

	//ft_putendl_fd("fini",2);
//	ft_putendl_fd("fini",2);



/*
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
	}*/
	free(e.piece);
	free(e.board);
	return (0);
}
