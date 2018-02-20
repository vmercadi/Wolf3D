/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:36 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 22:26:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <limits.h>
# define R 0xff0000
# define G 0x0000ff
# define B 0x00ff00
# define W 0xffffff
# define Y 0xffff00
# define WINX 800
# define WINY 800
# define NBTH 8

typedef struct			s_val
{
	int					win_size;
	int					sizeline;
	int					endian;
	int					stepx;
	int					stepy;
	int					sizev;
	int					winx;
	int					winy;
	int					maxx;
	int					maxy;
	int					size;
	int					wall;
	int					hit;
	int					bpp;
	int					xi;
	int					yi;
	int					x;
	int					**z;
	int					*data;
	char				*av;
	void				*mlx;
	void				*win;
	void				*img;
	double				rot;
	double				end;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				camx;
	double				rayx;
	double				rayy;
	double				start;
	double				angle;
	double				speed;
	double				odirx;
	double				planex;
	double				planey;
	double				wdistx;
	double				wdisty;
	double				wall_h;
	double				wall_w;
	double				dirrayx;
	double				dirrayy;
	double				oplanex;
	double				wdistxx;
	double				wdistyy;
	unsigned int		color;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_val;

/*
** Main & loop & init			|	wolf.c
*/

void					loop(t_val *v);
void					refresh(t_val *v);
void					init_v(t_val *v);
void					init_base(t_val *v);

/*
** Raycasting functions			|	raycasting.c
*/

void					raycasting(t_val *v);
void					draw_verti(t_val *v);
void					step(t_val *v);
void					hit(t_val *v);
void					wall(t_val *v);

/*
** Parsing the map				|	parsing.c
*/

int						get_z(t_val *v, char *line, int j);
void					check_file(char *av);
void					check_start(t_val *v);
void					parse(t_val *v);
void					get_xy(t_val *v, char *line);

/*
** All the events				|	event.c
*/

int						event(int k, void *param);
void					updown(int k, t_val *v);
void					leftright(int k, t_val *v);
void					ev_else(int k, t_val *v);
void					rotate(int k, t_val *v);

/*
** Utilitaries					|	utils.c
*/

int						clean(t_val *v);
void					error(int e);
void					get_color(t_val *v);
void					get_color2(t_val *v);
void					ui(t_val *val);

#endif
