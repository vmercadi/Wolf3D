/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/25 17:18:41 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Main loop
*/

void	loop(t_val *v)
{
	refresh(v);
	mlx_hook(v->win, 2, 0, event, v);
	mlx_hook(v->win, 17, 0, clean, v);
	mlx_loop(v->mlx);
}

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_val *v)
{
	int i;

	i = 0;
	while (i < WINX * WINY - 1)
		v->data[i++] = 0;
	raycasting(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	ui(v);
}

int		main(int ac, char **av)
{
	t_val v;

	if (ac != 2)
		error(1);
	if (!ft_strcmp(av[1], "usage"))
		error(0);
	v.av = ft_strdup(av[1]);
	check_file(av[1]);
	parse(&v);
	init_base(&v);
	check_start(&v);
	loop(&v);
	return (0);
}

/*
** Init the base struct
*/

void	init_base(t_val *v)
{
	v->color = 0;
	v->posx = 2;
	v->posy = 2;
	v->dirx = -1;
	v->diry = 0;
	v->planex = 0;
	v->planey = 0.66;
	v->bpp = 0;
	v->endian = 0;
	v->sizeline = 0;
	v->rot = 0.12;
	v->speed = 0.1;
	v->wall_w = 0;
	v->wall = 0;
	v->stepx = 0;
	v->stepy = 0;
	v->wdistx = 0;
	v->wdisty = 0;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINX, WINY, "Wolf3D");
	v->img = mlx_new_image(v->mlx, WINX, WINY);
	v->data = (int*)mlx_get_data_addr(
		v->img, &v->bpp, &v->sizeline, &v->endian);
}

/*
** Init the values for the loop
*/

void	init_v(t_val *v)
{
	v->camx = 2 * v->x / (double)WINX - 1;
	v->rayx = v->posx;
	v->rayy = v->posy;
	v->dirrayx = v->dirx + v->planex * v->camx;
	v->dirrayy = v->diry + v->planey * v->camx;
	v->xi = (int)v->rayx;
	v->yi = (int)v->rayy;
	v->wdistxx = sqrt(1 + (v->dirrayy * v->dirrayy) /
		(v->dirrayx * v->dirrayx));
	v->wdistyy = sqrt(1 + (v->dirrayx * v->dirrayx) /
		(v->dirrayy * v->dirrayy));
	v->hit = 0;
}
