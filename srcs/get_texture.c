/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:49:26 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/28 05:37:15 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), \
									&(tex->line_len), &(tex->en));
	if (!tex->addr)
		return (0);
	return (1);
}

static char	*get_env_path(int i)
{
	if (i == FLOOR)
		return (FLOOR_TEX_PATH);
	else if (i == WALL)
		return (WALL_TEX_PATH);
	else if (i == EXIT_OFF)
		return (EXIT_OFF_TEX_PATH);
	else
		return (EXIT_ON_TEX_PATH);
}

static char	*get_plr_path(int i)
{
	if (i == PLR_UP)
		return (PLR_UP_PATH);
	else if (i == PLR_DOWN)
		return (PLR_DOWN_PATH);
	else if (i == PLR_LEFT)
		return (PLR_LEFT_PATH);
	else
		return (PLR_RIGHT_PATH);
}

int	get_texture(t_win *win)
{
	int		i;

	if (!get_tex_img(win->mlx, CLLCT_TEX_PATH, &(win->cllct[0])))
		return (-1);
	i = 0;
	while (i < 4)
	{
		if (!get_tex_img(win->mlx, get_plr_path(i), &(win->plr[i])))
			return (-1);
		if (!get_tex_img(win->mlx, get_env_path(i), &(win->env[i])))
			return (-1);
		i += 1;
	}
	return (0);
}
