/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:00:45 by stmartin          #+#    #+#             */
/*   Updated: 2017/05/24 19:05:36 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_env
{
	char	*buff;
	char	**board;
	char	**piece;
	int		sbx;
	int		sby;
	int		px;
	int		py;
	int		spx;
	int		spy;
	int		playx;
	int		playy;
	int		play;
}				t_env;

char			goc(char c);
void			free_piece_and_board(t_env *e);
void			find_c_in_board(t_env *e, char c);
int				place_piece_on_board(t_env *e, int bx, int by, char c);
void			alloc_and_fill(t_env *e);
int				cut_map_horiz_for_x(t_env *e, char c, int xmax, int ymax);
int				cut_map_horiz_for_o(t_env *e, char c, int xmax, int ymax);
int				cut_the_map_for_x(t_env *e, char c, int xmax, int ymax);
int				cut_the_map_for_o(t_env *e, char c, int xmax, int ymax);

#endif
