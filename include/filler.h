/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:00:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/29 15:44:50 by stmartin         ###   ########.fr       */
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
}					t_env;

#endif
