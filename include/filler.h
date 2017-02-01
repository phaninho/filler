/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:00:45 by stmartin          #+#    #+#             */
/*   Updated: 2017/02/01 20:37:37 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct		s_env
{
	char	**board;
	char	*buff;
	char	**piece;
	int		sbx;
	int		sby;
	int		px;
	int		py;
	int		spx;
	int		spy;
	int		playx;
	int		playy;
	int		out;
	int		play;
}					t_env;

#endif
