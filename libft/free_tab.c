/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:30:43 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/25 17:14:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free a tab
*/

void	free_tab(void **tab)
{
	char	**tmp;

	tmp = (char **)tab;
	while (*tmp)
	{
		if (tmp)
			ft_strdel(tmp);
		tmp++;
	}
	free(tab);
}
