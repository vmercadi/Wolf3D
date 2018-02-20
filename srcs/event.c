/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/25 17:18:42 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Event for moving up and down
*/

void	updown(int k, t_val *v)
{
	if (k == 126 || k == 13)
	{
		if (!v->z[(int)(v->posx + v->dirx * v->speed)][(int)(v->posy)])
			v->posx += v->dirx * v->speed;
		if (!v->z[(int)(v->posx)][(int)(v->posy + v->diry * v->speed)])
			v->posy += v->diry * v->speed;
	}
	else if (k == 125 || k == 1)
	{
		if (!v->z[(int)(v->posx - v->dirx * v->speed)][(int)(v->posy)])
			v->posx -= v->dirx * v->speed;
		if (!v->z[(int)(v->posx)][(int)(v->posy - v->diry * v->speed)])
			v->posy -= v->diry * v->speed;
	}
	refresh(v);
}

/*
** Event for moving left and right
*/

void	leftright(int k, t_val *v)
{
	if (k == 2)
	{
		if (!v->z[(int)(v->posx + v->planex * v->speed)][(int)(v->posy)])
			v->posx += v->planex * v->speed;
		if (!v->z[(int)(v->posx)][(int)(v->posy + v->planey * v->speed)])
			v->posy += v->planey * v->speed;
	}
	else if (k == 0)
	{
		if (!v->z[(int)(v->posx - v->planex * v->speed)][(int)(v->posy)])
			v->posx -= v->planex * v->speed;
		if (!v->z[(int)(v->posx)][(int)(v->posy - v->planey * v->speed)])
			v->posy -= v->planey * v->speed;
	}
	refresh(v);
}

/*
** Event for rotating
*/

void	rotate(int k, t_val *v)
{
	if (k == 124)
	{
		v->odirx = v->dirx;
		v->dirx = v->dirx * cos(-v->rot) - v->diry * sin(-v->rot);
		v->diry = v->odirx * sin(-v->rot) + v->diry * cos(-v->rot);
		v->oplanex = v->planex;
		v->planex = v->planex * cos(-v->rot) - v->planey * sin(-v->rot);
		v->planey = v->oplanex * sin(-v->rot) + v->planey * cos(-v->rot);
	}
	else if (k == 123)
	{
		v->odirx = v->dirx;
		v->dirx = v->dirx * cos(v->rot) - v->diry * sin(v->rot);
		v->diry = v->odirx * sin(v->rot) + v->diry * cos(v->rot);
		v->oplanex = v->planex;
		v->planex = v->planex * cos(v->rot) - v->planey * sin(v->rot);
		v->planey = v->oplanex * sin(v->rot) + v->planey * cos(v->rot);
	}
	refresh(v);
}

/*
** For other events
*/

void	ev_else(int k, t_val *v)
{
	if (k == 53)
		clean(v);
	else if (k == 257)
		v->speed = (v->speed == 0.25) ? 0.15 : 0.25;
}

/*
** Redirect the events and show/hide menus
*/

int		event(int k, void *param)
{
	t_val *v;

	v = (t_val *)param;
	if (k == 126 || k == 125 || k == 13 || k == 1)
		updown(k, v);
	else if (k == 124 || k == 123)
		rotate(k, v);
	else if (k == 0 || k == 2)
		leftright(k, v);
	else if (k == 53 || k == 257)
		ev_else(k, v);
	return (0);
}
