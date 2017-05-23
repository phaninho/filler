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

# include "libft.h"
# include "mlx.h"

# define DESTROYNOTIFY 17
# define STRUCT_NOT_MASK (1L<<17)

typedef struct			s_image
{
	void			*i;
	int				bpp;
	int				szline;
	int				endian;
	char			*data;
	int				width;
	int				height;
}										t_image;

typedef struct		s_env
{
	char			c;
	char			*buff;
	char			**board;
	char			**piece;
	void 			*mlx;
	void			*win;
	t_image		img;
	int				sbx;
	int				sby;
	int				px;
	int				py;
	int				spx;
	int				spy;
	int				playx;
	int				playy;
	int				play;
}									t_env;

#endif
