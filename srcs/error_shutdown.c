/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_shutdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:31:32 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 01:22:13 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_error(char *err_ident, char *err_message)
{
	if (err_message)
	{
		ft_putendl_fd("Error", 2);
		if (err_ident)
		{
			ft_putstr_fd(err_ident, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putendl_fd(err_message, 2);
	}
}

void	err_shutdown(t_data *all, char *err_ident, char *err_message)
{
	put_error(err_ident, err_message);
	if (all->win->mlx)
		clear_game(all->win);
	free_struct(all);
	exit(1);
}
